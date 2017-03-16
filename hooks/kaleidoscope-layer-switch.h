/* -*- mode: c++ -*-
 * kaleidoscope-layer-switch.h -- Layer switching Focus hooks.
 * Copyright (C) 2017  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-Focus.h>

static bool focusLayer (const char *command) {
  enum {
    ON,
    OFF,
    GETSTATE,
  } subCommand;

  if (strncmp_P (command, PSTR ("layer."), 6) != 0)
    return false;

  if (strcmp_P (command + 6, PSTR ("on")) == 0)
    subCommand = ON;
  else if (strcmp_P (command + 6, PSTR ("off")) == 0)
    subCommand = OFF;
  else if (strcmp_P (command + 6, PSTR ("getState")) == 0)
    subCommand = GETSTATE;
  else
    return false;

  switch (subCommand) {
  case ON:
    {
      uint8_t layer = Serial.parseInt ();
      Layer.on (layer);
      break;
    }

  case OFF:
    {
      uint8_t layer = Serial.parseInt ();
      Layer.off (layer);
      break;
    }

  case GETSTATE:
    Serial.println (Layer.getLayerState (), BIN);
    break;
  }

  Serial.read ();
  return true;
}

#define FOCUS_LAYER_HOOK                            \
  FOCUS_HOOK(focusLayer,                            \
             "layer.on LAYER\n"                     \
             "--------------\n"                     \
             "Turns the LAYER layer on.\n\n"        \
             "layer.off LAYER\n"                    \
             "---------------\n"                    \
             "Turns the LAYER layer off.\n\n"       \
             "layer.getState\n"                     \
             "--------------\n"                     \
             "Display the current state of layers.")

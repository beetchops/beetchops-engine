/*
 *  Beetchops - real time audio sequencer
 *  Copyright (C) 2021 Anton Šefčík
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "engine.hpp"

#include <spdlog/spdlog.h>

#include <iostream>
#include <unistd.h>

using Beet_engn::Engine;

void Engine::start()
{
    _running = true;

    spdlog::info("{} Started.", log_label);

    while (_running) {
        sleep(1);
    }
}

void Engine::stop()
{
    _running = false;

    spdlog::info("{} Stopped.", log_label);
}

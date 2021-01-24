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

#include <catch2/catch.hpp>

#include <thread>

SCENARIO( "Engine can be started and stopped", "[engine]" )
{
    GIVEN( "initialized engine" )
    {
        Beet_engn::Engine engine;

        REQUIRE( engine.is_running() == false );

        WHEN( "the engine is started" )
        {
            std::thread engine_thread([&](){ engine.start(); });

            while (!engine.is_running()) { /* wait until it starts... TODO: add timeout */ }
            
            THEN( "the engine is running" )
            {
                REQUIRE( engine.is_running() == true );

                AND_WHEN( "the engine is stopped" )
                {
                    engine.stop();

                    THEN( "the engine is not running" )
                    {
                        REQUIRE( engine.is_running() == false );
                    }
                }
            }

            engine_thread.join();
        }
    }
}

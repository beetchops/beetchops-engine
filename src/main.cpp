/*
 *  Beetchops - real time audio sequencer
 *  Copyright (C) 2020 Anton Šefčík
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

#include <spdlog/spdlog.h>

#include <stdexcept>
#include <string>

namespace Beetchops_engine {
    static constexpr std::string_view log_label{"[beetchops-engine]:"};

    void print_current_exception_with_nested(int level = 0)
    {
        try {
            // re-throw current exception
            throw;
        }
        catch (const std::exception& err) {
            // it's std::exception, print it
            spdlog::error("\t{}exception: {}", std::string(level, ' '), err.what());
        }
        catch(...) {
            // it's an unknown exception, print message
            spdlog::error("\t{}unknown exception", std::string(level, ' '));
        }

        try {
            // re-throw current exception
            throw;
        }
        catch (const std::nested_exception& nested) {
            // it's std::nested_exception (meaning it in fact contains a nested exception)
            try {
                // re-throw nested exception
                nested.rethrow_nested();
            }
            catch (...) {
                // catch it and print it with its nested exceptions, if any
                print_current_exception_with_nested(level + 1); // recursion
            }
        }
        catch (...) {
            //it's not std::nested_exception - do nothing - end recursion
        }
    }

    static void exit_with_error(std::string msg)
    {
        spdlog::error("{} {}", log_label, msg);
        print_current_exception_with_nested();
        spdlog::error("{} Exiting...", log_label);
        exit(1);
    }
}

int main()
try {
    spdlog::info("{} Started.", Beetchops_engine::log_label);
    return 0;
}
catch (const std::runtime_error& err) {
    Beetchops_engine::exit_with_error("Runtime error occurred:");
}
catch (const std::exception& err) {
    Beetchops_engine::exit_with_error("Error occurred:");
}
catch (...) {
    Beetchops_engine::exit_with_error("Unknown error occurred.");
}

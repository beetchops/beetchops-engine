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

#include <string>

namespace Beetchops_engine {
    static constexpr std::string_view log_label{"[beetchops-engine]:"};
}

int main() {
    spdlog::info("{} Started.", Beetchops_engine::log_label);
    return 0;
}

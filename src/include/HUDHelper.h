#ifndef TRAPDOOR_MINIHUD_HELPER_H
#define TRAPDOOR_MINIHUD_HELPER_H
#include <array>
#include <unordered_map>

#include "CommandHelper.h"

namespace tr {
    enum HUDInfoType {
        Base = 0,
        Mspt = 1,
        Vill = 2,
        Redstone = 3,
        Counter = 4,
        Unknown = 5,
    };

    struct PlayerHudInfo {
        std::string realName;
        bool enable;
        std::array<int, 4> config{};
    };

    class HUDHelper {
       public:
        inline ActionResult setAble(bool able) {
            this->enable = able;
            return {"Success", true};
        }

        void tick();

        ActionResult modifyPlayerInfo(const std::string& playerName, const std::string& item,
                                      int op);

        ActionResult setAblePlayer(const std::string& playerName, bool able);

       private:
        bool enable = false;
        std::unordered_map<std::string, PlayerHudInfo> playerInfos;
    };

}  // namespace tr

#endif

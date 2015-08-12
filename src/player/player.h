#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H

#include <string>

namespace risk {
namespace player {

class player {
    std::string name_;
public:
    using id = std::size_t;
    static const player null;

    player(const std::string name);
    virtual ~player();

    inline const std::string name() const {
        return name_;
    }
};

}
}

#endif /* PLAYER_PLAYER_H */

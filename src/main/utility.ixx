export module utility;

import <iostream>;
import <string>;

export namespace result
{
    constexpr auto FAIL = -1;
    constexpr auto SUCCESS = 0;
}

export namespace util
{

    auto exitMainWithFailure(const std::string& msg) -> int
    {
        std::cerr << msg;
        return result::FAIL;
    }
}

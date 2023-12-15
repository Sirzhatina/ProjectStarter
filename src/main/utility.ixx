export module utility;

import <iostream>;
import <string>;

export auto exitMainWithFailure(const std::string& msg) -> int
{
    constexpr auto failureSign = -1;

    std::cerr << msg;
    return failureSign;
}


#include "CallbackRunner.h"

#include <cstdio>
#include <sol.hpp>

int main(int argc, char *argv[])
{
    // Make sure CLI arguments include path to the script.
    if (argc != 2)
    {
        printf("%s /path/to/script.lua\n", argv[0]);
        return 1;
    }
    // Path to the script.
    const char *fileName = argv[1];

    // Create lua state.
    sol::state lua;
    lua.open_libraries();

    // Register callback runner and its instance instance.
    CallbackRunner runner;
    lua["runner"] = &runner;
    lua.new_usertype<CallbackRunner>(
        "CallbackRunner",
        "call",
        [](CallbackRunner &runner, CallbackContainer *c, sol::nested<Strings> values)
        {
            return runner.call(c, values);
        }
    );

//#define REGISTER_PLAIN_CALLBACK

    // Register callback container.
    lua.new_usertype<CallbackContainer>(
        "CallbackContainer",
        "callback",
#ifdef REGISTER_PLAIN_CALLBACK
        &CallbackContainer::callback
#else // REGISTER_PLAIN_CALLBACK
        sol::property(
            [](CallbackContainer &c, sol::function luaCallback)
            {
                c.callback =
                    [=](const Strings &values) -> Strings
                    {
                        sol::nested<Strings> result = luaCallback(sol::as_table(values));
                        return std::move(result.source);
                    };
            })
#endif // REGISTER_PLAIN_CALLBACK
    );

    // Load and execute script.
    lua.script_file(fileName);

    return 0;
}

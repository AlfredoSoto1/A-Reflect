
root = "../../"
output_binaries = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

-- The workspace refers to the vs-solution name
workspace "A-Reflect"
    location (root)
    architecture "x64"
    configurations {
        "debug",
        "release",
        "dist",
    }
    startproject "testing"

include "dependencies.lua"

include "../projects/setup-testing.lua"

group "core"
    include "../projects/setup-core.lua"
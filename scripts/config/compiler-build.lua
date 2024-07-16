filter "configurations:debug"
    runtime "debug"
    symbols "on"
    defines {"SOFTWARE_DEBUG"}

filter "configurations:release"
    runtime "release"
    optimize "on"
    symbols "on"
    defines {"SOFTWARE_RELEASE"}

filter "configurations:dist"
    runtime "release"
    optimize "on"
    symbols "off"
    defines {"SOFTWARE_DISTRIBUTION"}
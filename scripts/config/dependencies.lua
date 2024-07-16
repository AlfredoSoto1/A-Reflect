
function filter_include_VULKAN()
    -- Configuration for Windows
    filter "system:windows"
        includedirs {
            root.. "dependencies/glfw/include",   -- GLFW headers directory
            root.. "dependencies/vulkan/include", -- VULKAN headers directory
        }
        libdirs {
            root.. "dependencies/glfw/lib",   -- GLFW libraries directory     
            root.. "dependencies/vulkan/lib", -- VULKAN libraries directory  
        }
        links {
            "glfw3",    -- GLFW library (glfw3.lib)
            "vulkan-1", -- Vulkan library (vulkan-1.lib)
        }

    -- Configuration for Linux
    filter "system:linux"
        includedirs {
            "/usr/include",       -- Standard Linux headers directory
            "/usr/include/vulkan" -- Vulkan headers directory
        }
        libdirs {
            "/usr/lib",           -- Standard Linux libraries directory
        }
        links {
            "glfw",     -- Link GLFW library (libglfw.so)
            "vulkan",   -- Link Vulkan library (libvulkan.so)
            "dl",       -- Link Dynamic Loading library (libdl.so)
            "pthread",  -- Link POSIX Threads library (libpthread.so)
        }
end

function filter_include_OPENGL()
    --  Define key to allow glew to be enabled for static linking
    defines "GLEW_STATIC"

    -- Configuration for Windows
    filter "system:windows"
        includedirs {
            root.. "dependencies/glfw/include", -- GLFW headers directory
            root.. "dependencies/glew/include", -- GLEW headers directory
        }
        libdirs {
            root.. "dependencies/glfw/lib", -- GLFW libraries directory     
            root.. "dependencies/glew/lib", -- GLEW libraries directory  
        }
        links {
            "glew32s",  -- GLEW static library (glew32s.lib)
            "glfw3",    -- GLFW library (glfw3.lib)
            "opengl32", -- OpenGL library (opengl32.lib)
            "User32",   -- User32 library for Windows API (User32.lib)
            "Gdi32",    -- Gdi32 library for GDI functions (Gdi32.lib)
            "Shell32",  -- Shell32 library for shell functions (Shell32.lib)
        }

    -- Configuration for Linux
    filter "system:linux"
        includedirs {
            "/usr/include",    -- Standard Linux headers directory
            "/usr/include/GL", -- OpenGL headers directory
        }
        libdirs {
            "/usr/lib",        -- Standard Linux libraries directory
        }
        links {
            "glfw",     -- Link GLFW library (libglfw.so)
            "GLEW",     -- Link GLEW library (libGLEW.so)
            "GL",       -- Link OpenGL library (libGL.so)
            "dl",       -- Link Dynamic Loading library (libdl.so)
            "pthread",  -- Link POSIX Threads library (libpthread.so)
        }
end

function includeDependencies_OPENAL()
    -- Configuration for Windows
    filter "system:windows"
        includedirs {
            root.. "dependencies/openal/include", -- OPENAL headers directory
        }
        libdirs {
            root.. "dependencies/openal/lib", -- OPENAL libraries directory     
        }
        links {
            "OpenAL32", -- OPENAL static library (Openal32.lib)
            "kernel32", -- kernel32 library (kernel32.lib)
        }

    -- Configuration for Linux
    filter "system:linux"
        includedirs {
            "/usr/include",   -- Standard Linux headers directory
            "/usr/include/AL" -- OpenAL headers directory
        }
        libdirs {
            "/usr/lib",       -- Standard Linux libraries directory
        }
        links {
            "openal",         -- Link OpenAL library (libopenal.so)
            "pthread"         -- Link POSIX Threads library (libpthread.so)
        }
end

function filter_include_GLM()
    -- Configuration for GLM (header-only library, so no linking needed)
    filter "system:windows"
        includedirs {
            root .. "dependencies/glm" -- GLM headers directory
        }
    filter "system:linux"
        includedirs {
            root .. "dependencies/glm" -- GLM headers directory
        }
end

function filter_include_STB()
    -- Configuration for STB (header-only library, so no linking needed)
    filter "system:windows"
        includedirs {
            root .. "dependencies/stb" -- GLM headers directory
        }
    filter "system:linux"
        includedirs {
            root .. "dependencies/stb" -- GLM headers directory
        }
end

function filter_include_ALL()
    -- Include dependencies for OpenGL
    filter_include_OPENGL()

    -- Include dependencies for Vulkan
    filter_include_VULKAN()

    -- Include dependencies for OpenAL
    includeDependencies_OPENAL()

    -- Include dependencies for GLM
    includeDependencies_GLM()

    -- Include dependencies for STB
    includeDependencies_STB()
end
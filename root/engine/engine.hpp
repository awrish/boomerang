// Project Boomerang : engine/engine.hpp (c) 2020 Andrew Woo, Porter Squires, Brandon Yau, and Awrish Khan

/* Modified MIT License
 *
 * Copyright 2020 Andrew Woo, Porter Squires, Brandon Yau, and Awrish Khan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * Restrictions:
 >  The Software may not be sold unless significant, mechanics changing modifications are made by the seller, or unless the buyer
 >  understands an unmodified version of the Software is available elsewhere free of charge, and agrees to buy the Software given
 >  this knowledge.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#ifndef BOOMERANG_ENGINE_ENGINE
#define BOOMERANG_ENGINE_ENGINE

// Include standard library
#include <string>
#include <vector>

// Include dependencies
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

// Include boomerang libraries
#include "../misc/utilities.hpp"

namespace Boomerang::Core {

    class Engine {

        // Project Boomerang Engine

    public:

        // Constructor
        Engine(std::string _WindowTitle = "Boomerang", util::dimen2d<int> _WindowDimensions = util::dimen2d<int>(1000, 618));

        // Destructor
        ~Engine();

        // Initialize Engine
        int init();

        struct Metadata {       // This struct contains the metadata for the engine/glfwWindow. The data inside should be set BEFORE the engine is initialized.

            // Engine metadata
            bool autoinit = true;               // Automatically initialize engine components
            bool debugmode = false;             // Enable debug mode
            bool loggingEnabled = true;         // Enable logging

            std::vector<float> clearcolor = { 1.f, 1.f, 1.f, 0.f }; // Render surface clear color
            //RendererType rendermode = RendererType::Render_2D;      // Engine render mode

            //Version version;                                // Application version

            // GLFW window initialization metadata
            std::vector<std::pair<int, int>> windowHints{ { std::make_pair(GLFW_CLIENT_API, GLFW_OPENGL_API),       // Window hints _ default (GLFW_CLIENT_API, GLFW_OPENGL_API)
                                                            std::make_pair(GLFW_RESIZABLE, GLFW_FALSE) } };         // Window hints _ default (GLFW_RESIZABLE, GLFW_FALSE)

        }; Metadata metadata;

        // Engine Functions
        void Update() const;            // Update engine

        // Getters
        GLFWwindow* GetWindow();

    private:

        GLFWwindow* window;

        std::string WindowTitle;
        util::dimen2d<int> WindowDimensions;
    };
}

#endif // !BOOMERANG_ENGINE_ENGINE
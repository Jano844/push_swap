# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.18.4)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(imgui-sfml-populate NONE)

include(ExternalProject)
ExternalProject_Add(imgui-sfml-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/eliasdaler/imgui-sfml" "GIT_TAG" "82dc2033e51b8323857c3ae1cf1f458b3a933c35"
                    SOURCE_DIR          "/home/jan/Documents/C/42/push_swap42_test/build/_deps/imgui-sfml-src"
                    BINARY_DIR          "/home/jan/Documents/C/42/push_swap42_test/build/_deps/imgui-sfml-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)



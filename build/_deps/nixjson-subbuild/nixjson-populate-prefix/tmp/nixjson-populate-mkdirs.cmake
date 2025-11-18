# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspaces/JogoDePerguntas/build/_deps/nixjson-src"
  "/workspaces/JogoDePerguntas/build/_deps/nixjson-build"
  "/workspaces/JogoDePerguntas/build/_deps/nixjson-subbuild/nixjson-populate-prefix"
  "/workspaces/JogoDePerguntas/build/_deps/nixjson-subbuild/nixjson-populate-prefix/tmp"
  "/workspaces/JogoDePerguntas/build/_deps/nixjson-subbuild/nixjson-populate-prefix/src/nixjson-populate-stamp"
  "/workspaces/JogoDePerguntas/build/_deps/nixjson-subbuild/nixjson-populate-prefix/src"
  "/workspaces/JogoDePerguntas/build/_deps/nixjson-subbuild/nixjson-populate-prefix/src/nixjson-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspaces/JogoDePerguntas/build/_deps/nixjson-subbuild/nixjson-populate-prefix/src/nixjson-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspaces/JogoDePerguntas/build/_deps/nixjson-subbuild/nixjson-populate-prefix/src/nixjson-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

cmake_minimum_required(VERSION 3.0)

set(MercurySilver_SOURCES
    src/MercurySilver.h
    src/MercurySilver.cpp
)

add_library(MercurySilver SHARED ${MercurySilver_SOURCES})
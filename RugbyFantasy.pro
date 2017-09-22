TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread \
        -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system \
        -lboost_regex -lboost_filesystem -lboost_system

SOURCES += main.cpp \
    engine/engine.cpp \
    engine/models/scene.cpp \
    game/graphics/scenes/map_scene.cpp \
    engine/drawable.cpp \
    engine/updatable.cpp \
    engine/graphics/animated_sprite.cpp \
    engine/graphics/animation.cpp \
    engine/graphics/sprite.cpp \
    engine/resources/textures_cache.cpp \
    engine/graphics/animations/sprite_animation.cpp \
    engine/window.cpp \
    utils/timer.cpp \
    utils/file.cpp \
    utils/directory.cpp \
    utils/key_limitor.cpp \
    utils/exception.cpp \
    engine/graphics/mouse_scene.cpp \
    engine/events.cpp \
    engine/events/event_subscriber.cpp \
    engine/events/event.cpp \
    engine/events/mouse_move_event.cpp

HEADERS += \
    engine/engine.hpp \
    engine/models/scene.hpp \
    game/graphics/scenes/map_scene.hpp \
    engine/drawable.hpp \
    engine/updatable.hpp \
    engine/graphics/animated_sprite.hpp \
    engine/graphics/animation.hpp \
    engine/graphics/sprite.hpp \
    engine/resources/textures_cache.hpp \
    engine/graphics/animations/sprite_animation.hpp \
    engine/window.hpp \
    utils/timer.hpp \
    utils/file.hpp \
    utils/directory.hpp \
    utils/key_limitor.hpp \
    utils/exception.hpp \
    engine/graphics/mouse_scene.hpp \
    engine/events.hpp \
    engine/events/event_subscriber.hpp \
    engine/events/event_types.hpp \
    engine/events/event.hpp \
    engine/events/mouse_move_event.hpp


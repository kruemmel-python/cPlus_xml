#include <iostream>
#include "pugixml.hpp"  // pugixml einbinden

int main() {
    setlocale(LC_ALL, "de_DE");
    // XML-Dokument laden
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("settings.xml");

    // Fehlerbehandlung
    if (!result) {
        std::cerr << "Fehler beim Laden der Datei: " << result.description() << std::endl;
        return 1;
    }

    // Hauptknoten "Settings" abrufen
    pugi::xml_node settings = doc.child("Settings");

    // Zugriff auf "Graphics"-Einstellungen
    pugi::xml_node graphics = settings.child("Graphics");
    int width = graphics.child("Resolution").attribute("width").as_int();
    int height = graphics.child("Resolution").attribute("height").as_int();
    const char* fullscreen = graphics.child("Resolution").attribute("fullscreen").as_string();
    bool vsyncEnabled = graphics.child("VSync").attribute("enabled").as_bool();
    int antiAliasingLevel = graphics.child("AntiAliasing").attribute("level").as_int();

    // Ausgabe der "Graphics"-Einstellungen
    std::cout << "Graphics Settings:" << std::endl;
    std::cout << "Resolution: " << width << "x" << height << ", Fullscreen: " << fullscreen << std::endl;
    std::cout << "VSync Enabled: " << std::boolalpha << vsyncEnabled << std::endl;
    std::cout << "AntiAliasing Level: " << antiAliasingLevel << std::endl;

    // Zugriff auf "Audio"-Einstellungen
    pugi::xml_node audio = settings.child("Audio");
    int masterVolume = audio.child("MasterVolume").attribute("level").as_int();
    int musicVolume = audio.child("MusicVolume").attribute("level").as_int();
    int effectsVolume = audio.child("EffectsVolume").attribute("level").as_int();

    // Ausgabe der "Audio"-Einstellungen
    std::cout << "\nAudio Settings:" << std::endl;
    std::cout << "Master Volume: " << masterVolume << std::endl;
    std::cout << "Music Volume: " << musicVolume << std::endl;
    std::cout << "Effects Volume: " << effectsVolume << std::endl;

    // Zugriff auf "Controls"-Einstellungen
    pugi::xml_node controls = settings.child("Controls");
    const char* moveForward = controls.child("MoveForward").attribute("key").as_string();
    const char* moveBackward = controls.child("MoveBackward").attribute("key").as_string();
    const char* moveLeft = controls.child("MoveLeft").attribute("key").as_string();
    const char* moveRight = controls.child("MoveRight").attribute("key").as_string();
    const char* jump = controls.child("Jump").attribute("key").as_string();
    const char* crouch = controls.child("Crouch").attribute("key").as_string();

    // Ausgabe der "Controls"-Einstellungen
    std::cout << "\nControls Settings:" << std::endl;
    std::cout << "Move Forward: " << moveForward << std::endl;
    std::cout << "Move Backward: " << moveBackward << std::endl;
    std::cout << "Move Left: " << moveLeft << std::endl;
    std::cout << "Move Right: " << moveRight << std::endl;
    std::cout << "Jump: " << jump << std::endl;
    std::cout << "Crouch: " << crouch << std::endl;

    // Am Ende des Programms warten
    std::cout << "\nDrücke Enter, um das Programm zu beenden...";
    std::cin.get();  // Wartet auf eine Benutzereingabe

    return 0;
}

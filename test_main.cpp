#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pugixml.hpp"  // pugixml einbinden
#include <iostream>
#include <locale>



// Test für das erfolgreiche Laden einer XML-Datei
TEST_CASE("Test für das Laden einer XML-Datei") {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("settings.xml");

    // Überprüfe, ob die Datei erfolgreich geladen wurde
    CHECK(result);  // Das sollte true sein, wenn das Laden erfolgreich ist
}

// Test für das Auslesen der Auflösung aus den Grafikeinstellungen
TEST_CASE("Test für das Auslesen der Grafikeinstellungen") {
    pugi::xml_document doc;
    doc.load_file("settings.xml");

    // Die Grafikeinstellungen auslesen
    pugi::xml_node graphics = doc.child("Settings").child("Graphics");  // Korrigiert
    int width = graphics.child("Resolution").attribute("width").as_int();
    int height = graphics.child("Resolution").attribute("height").as_int();

    // Überprüfe, ob die Auflösung korrekt ausgelesen wird
    CHECK(width == 1920);
    CHECK(height == 1080);
}

// Test für das Auslesen der Audio-Einstellungen
TEST_CASE("Test für das Auslesen der Audioeinstellungen") {
    pugi::xml_document doc;
    doc.load_file("settings.xml");

    // Die Audioeinstellungen auslesen
    pugi::xml_node audio = doc.child("Settings").child("Audio");  // Korrigiert
    int masterVolume = audio.child("MasterVolume").attribute("level").as_int();

    // Überprüfen, ob der Master-Volume korrekt ist
    CHECK(masterVolume == 80);
}

// Zusätzlicher Test für eine Pause nach den Tests
TEST_CASE("Pause nach den Tests") {
    setlocale(LC_ALL, "de_DE");
    std::cout << "Drücke Enter, um das Programm zu beenden...";
    std::cin.get();  // Wartet auf die Eingabe der Enter-Taste
}

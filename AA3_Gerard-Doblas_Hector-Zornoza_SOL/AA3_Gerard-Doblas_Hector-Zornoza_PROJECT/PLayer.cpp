#include "Player.h"
#include "conio.h"


void Player::PlayerMove()
{
    char input; // Para capturar la entrada del usuario

    while (agility > 0) {

        input = _getch(); // Capturar la tecla presionada
        int newX = x;
        int newY = y;

        // Determinar nueva posición según la tecla
        switch (input) {
        case 'w': // Mover hacia arriba
        case 'W':
            newY--;
            break;
        case 's': // Mover hacia abajo
        case 'S':
            newY++;
            break;
        case 'a': // Mover hacia la izquierda
        case 'A':
            newX--;
            break;
        case 'd': // Mover hacia la derecha
        case 'D':
            newX++;
            break;
        default:
            std::cout << "Entrada inválida. Usa W, A, S, D o Q.\n";
            continue; // Reintentar si la entrada es inválida
        }

        // Verificar si la nueva posición es válida
        if (map.IsValidPosition(newX, newY)) {
            // Borrar el carácter anterior
            gotoxy(character.x, character.y);
            std::cout << ' ';

            // Actualizar la posición del jugador
            character.x = newX;
            character.y = newY;

            // Mover el cursor y mostrar al jugador
            SetCharacterPos(character, newX, newY);
        }
        else {
            std::cout << "Movimiento inválido. Intenta nuevamente.\n";
        }
    }
}

}
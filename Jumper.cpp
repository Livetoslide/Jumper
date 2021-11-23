// Jumper.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>

using namespace sf;
struct point
{
    int x, y;
};
bool GameOver = false;

bool game() {
    srand(time(0));

    RenderWindow app(VideoMode(400, 533), "Game");
    app.setFramerateLimit(60);
    Texture t1, t2, t3, t4;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform2.png");
    t3.loadFromFile("images/doodle.png");
    t4.loadFromFile("images/platform3.png");
    Sprite sBackground(t1), sPlat(t2), sPers(t3), sPlat2(t4);

    point plat[10];
    point plat2[10];
    //Спавн координат бутылок
    for (int i = 0; i < 5; i++)
    {
        plat[i].x = rand() % 350;
        plat[i].y = rand() % 620;
        plat2[i].x = rand() % 350;
        plat2[i].y = rand() % 620;
        

    }

    // Звук пук
    SoundBuffer buffer;
    buffer.loadFromFile("sounds/op.ogg");
    Sound sound;
    sound.setBuffer(buffer);
    //Звук музыка
    Music mainmus;
    mainmus.openFromFile("sounds/main_theme.ogg");
    mainmus.setPlayingOffset(seconds(1.5));
    mainmus.play();

    int x = 100, y = 0, h = 200;
    int maxX = 400;
    int MinX = 0;
    float dx = 0, dy = 0;
    

    while (app.isOpen())
    {


        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right) && (x < maxX - 50)) x += 4;
        if (Keyboard::isKeyPressed(Keyboard::Left) && (x > MinX - 30)) x -= 4;

        dy += 0.2;
        y += dy;
        if (y > 500) dy = -10;


        if (y < h)
            for (int i = 0; i < 5; i++)
            {
                y = h;
                plat[i].y = plat[i].y - dy;
                plat2[i].y = plat2[i].y - dy;
                if (plat[i].y > 533 && plat2[i].y > 533)
                {
                    plat[i].y = 0;
                    plat[i].x = rand() % 400;
                    plat2[i].y = 0;
                    plat2[i].x = rand() % 400;
                }
            }


        for (int i = 0; i < 5; i++)
        {
            
            if ((x + 15 > plat[i].x) && (x + 5 < plat[i].x + 65)
                && (y + 40 > plat[i].y) && (y + 70 < plat[i].y + 75) && (dy > 0)) {
                dy -= 16;
                sound.play();
            }
            else if ((x + 15 > plat2[i].x) && (x + 5 < plat2[i].x + 65)
                && (y + 40 > plat2[i].y) && (y + 70 < plat2[i].y + 75) && (dy > 0))
            {
                dy -= 16;
                sound.play();
            }

        }


        sPers.setPosition(x, y);
        if (sPers.getPosition().y > 500) GameOver = true;

        if (GameOver == true) {
            return GameOver;
        }



        app.draw(sBackground);
        for (int i = 0; i < 5; i++)

        {
            sPlat.setPosition(plat[i].x, plat[i].y);
            sPlat2.setPosition(plat2[i].x, plat2[i].y);
            app.draw(sPlat);
            app.draw(sPlat2);

        }
        app.draw(sPers);

        app.display();
    }
}

int main()
{
    while (GameOver == false)
    {
        game();
        if (GameOver = true) {
            GameOver = false;
        }
    }


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

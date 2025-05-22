# Sistema de Inventario de un Videojuego
##   Programación Orientada a Objetos - A01713396 
Dentro de este proyecto se logrará realizar un sistema de inventario de un videojuego de genero roguelike, donde se maneje de manera eficiente los objetos que objetos cuenta el jugador, al igual que el jugador puede vender el objeto por el valor de monedas correspondiente con la rareza del objeto.
Esta idea proviene de juegos roguelike como lo podrian ser Enter The GunGeon, Dead Cells, Minecraft Dungeons, Binding Of Isaac, etc. el proposito principal de este sistema de inventario es actualizarlo e introducirlo en un juego propio si el tiempo disponible nos permite realizarlo. 

## Funcionamiento
Este  proyecto cuenta con metódos como agregar un objeto, vender el objeto, consumir el objeto (en caso de ser un objeto consumible), equipar el objeto si es un objeto de la clase equipamento (armadura o arma/espada). 

## Casos donde hay fallo. 
De momento como nos encontramos en etapas muy tempranas no habrían muchas fallos, sin embargo en un futuro alguno de los errores que se pueden presentar:
-Intentar interactuar con un objeto que sea null.
-Que el usuario pueda contar con mayor cantidad de un mismo objeto en un stack (en un conjunto completo de objeto).
-Usar un objeto que ya no se puede utilizar (siendo un consumible ya consumido o un arma sin munición).

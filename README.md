# 🧱 so_long

> Proyecto de programación gráfica en C con MiniLibX - 42 Cursus

---

## 🎮 Descripción

**so_long** es un juego en 2D de un solo jugador, desarrollado en **C** utilizando la **MiniLibX**, una pequeña biblioteca gráfica proporcionada por la Escuela 42.

El objetivo del juego es **recoger todos los objetos**, **llegar a la salida** y evitar enemigos (si se implementan).  
El mapa es leído desde un archivo `.ber` y debe estar rodeado de paredes.

---

## 🕹️ Controles

El personaje se mueve usando las **flechas del teclado**:

- ⬆️ Flecha arriba → Mover hacia **arriba**
- ⬇️ Flecha abajo → Mover hacia **abajo**
- ⬅️ Flecha izquierda → Mover hacia **la izquierda**
- ➡️ Flecha derecha → Mover hacia **la derecha**
- ❌ `ESC` → Cierra el juego

Cada movimiento válido incrementa el contador de movimientos, que se muestra por pantalla o en consola.

---

## 🧩 Reglas del juego

- El jugador (`P`) debe recoger todos los objetos (`C`) y llegar a la salida (`E`).
- El mapa debe tener al menos:
  - 1 jugador (`P`)
  - 1 salida (`E`)
  - 1 coleccionable (`C`)
- El mapa debe estar cerrado por muros (`1`) y no puede tener líneas irregulares.
- Los espacios vacíos se representan con `0`.
- Si el mapa no es válido, el programa debe mostrar un mensaje de error y salir correctamente.

---

## 📁 Formato del mapa

Archivo con extensión `.ber`. Ejemplo:

```
111111
1P0C01
100001
1C0E11
111111
```

Significado:
- `1` → Muro
- `0` → Espacio vacío
- `P` → Jugador
- `C` → Coleccionable
- `E` → Salida

---

## 📦 Compilación

```bash
make
```

Esto generará el ejecutable del juego.

---

## 🚀 Ejecución

```bash
./so_long maps/mapa.ber
```

Asegúrate de tener un archivo `.ber` válido en la carpeta `maps/` o la ruta que utilices.

---

## 🎨 Recomendaciones gráficas

- Se recomienda un tamaño uniforme por bloque (por ejemplo, 64x64 px).
- Asegúrate de cargar bien las texturas antes de comenzar el bucle del juego.

---

## 🔍 Cosas a verificar

- ❗ Gestión de errores si el archivo no existe o es inválido.
- ✅ Liberación de memoria correctamente al cerrar el juego.
- 🧠 Validación del mapa antes de renderizar.
- 🎯 El jugador no debe poder moverse a través de muros.

---

## 📌 Nota

Este proyecto te enseña sobre:
- Lectura y validación de archivos
- Programación de eventos con MiniLibX
- Gestión de memoria
- Bucle de renderizado y dibujo de sprites

---

¡Disfruta programando y jugando tu propio mini-juego 2D! 🎉
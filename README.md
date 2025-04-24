# so_long

> Proyecto de gráficos básicos en 2D del curriculum de 42

## 🧩 Descripción

`so_long` es un pequeño videojuego en 2D desarrollado como parte del programa 42. El objetivo es familiarizarse con el uso de una librería gráfica sencilla (MiniLibX) y aplicar conocimientos de programación estructurada y manejo de eventos.

El jugador debe moverse por un mapa cerrado, recolectar todos los objetos y llegar a la salida para ganar. El juego termina si el jugador alcanza la salida sin haber recogido todos los objetos.

---

## 🎯 Objetivos

- Cargar y validar mapas desde archivos `.ber`.
- Renderizar gráficos 2D utilizando MiniLibX.
- Detectar y gestionar eventos de teclado.
- Implementar lógica de movimiento y condiciones de victoria.
- Manejar errores y memoria correctamente.

---

## 🛠️ Tecnologías

- C
- MiniLibX (librería gráfica simple proporcionada por 42)
- macOS / Linux

---

## 📦 Instalación

1. Clona el repositorio:
```bash
git clone https://github.com/tu_usuario/so_long.git
cd so_long
```

2. Compila el proyecto:
```bash
make
```

> Asegúrate de tener MiniLibX y las dependencias necesarias instaladas (como X11 en Linux).

---

## 🕹️ Cómo jugar

Ejecuta el juego con un mapa `.ber`:

```bash
./so_long maps/mapa1.ber
```

**Controles:**
- `W` / `A` / `S` / `D` — Moverse
- `ESC` — Salir del juego

---

## 🗺️ Formato del Mapa

- `1` → Pared
- `0` → Suelo
- `P` → Posición inicial del jugador
- `C` → Coleccionable
- `E` → Salida

Ejemplo:
```
11111
1P0C1
10001
1C0E1
11111
```

---

## ✅ Reglas de Validación

- El mapa debe ser rectangular.
- El mapa debe estar completamente cerrado por paredes (`1`).
- Debe contener exactamente un `P`, al menos un `C` y una `E`.

---

## 📄 Licencia

Este proyecto es parte del programa 42 y está destinado exclusivamente a fines educativos.

---

## ✍️ Autor

lruiz-to

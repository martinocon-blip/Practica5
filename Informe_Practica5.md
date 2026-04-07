# PRÁCTICA 5 - BUSES DE COMUNICACIÓN I (I2C)

## Autor
Ivan (KIDBU)

---

# 1. INTRODUCCIÓN

El objetivo de esta práctica es comprender el funcionamiento del bus de comunicación I2C y su uso para la comunicación entre un microcontrolador y distintos dispositivos periféricos.

En esta práctica se ha trabajado con:
- ESP32-S3 DevKitC-1
- Display OLED SSD1306 (I2C)
- Simulación de sensor biométrico (frecuencia cardíaca y SpO2)

---

# 2. DESCRIPCIÓN DEL BUS I2C

El bus I2C (Inter-Integrated Circuit) es un protocolo de comunicación serie que utiliza únicamente dos líneas:

- SDA (datos)
- SCL (reloj)

Permite la comunicación entre múltiples dispositivos mediante direcciones únicas, siendo el microcontrolador el maestro y los periféricos los esclavos.

---

# 3. EJERCICIO 1 - ESCÁNER I2C

## Funcionamiento

Se ha implementado un escáner I2C que recorre todas las direcciones posibles del bus para detectar dispositivos conectados.

El programa intenta comunicarse con cada dirección y verifica si existe respuesta.

## Salida por puerto serie

```
Scanning...
I2C device found at address 0x3C !
done
```

## Conclusión

Se ha detectado correctamente el dispositivo OLED en la dirección 0x3C, verificando el correcto funcionamiento del bus I2C.

---

# 4. MONTAJE DEL SISTEMA

## Conexiones realizadas

| OLED | ESP32-S3 |
|------|----------|
| VCC  | 3.3V |
| GND  | GND |
| SDA  | GPIO 8 |
| SCL  | GPIO 9 |

Todos los dispositivos comparten el mismo bus I2C.

---

# 5. EJERCICIO 2 - DISPLAY OLED

## Objetivo

Mostrar información en el display OLED utilizando comunicación I2C.

## Desarrollo

Se han implementado distintas funcionalidades:
- Visualización de texto
- Actualización dinámica de datos
- Animaciones básicas
- Uso de funciones gráficas

---

# 6. PARTE 1 - VISUALIZACIÓN DE DATOS BIOMÉTRICOS

## Objetivo

Mostrar en el display:
- Frecuencia cardíaca (HR)
- Saturación de oxígeno (SpO2)

## Implementación

Debido a la ausencia del sensor físico MAX30102, se ha optado por simular los valores biométricos.

### Funcionamiento

El sistema genera valores aleatorios dentro de rangos realistas:

- HR: 60 - 100 bpm
- SpO2: 95 - 100 %

Estos datos se muestran en tiempo real en el display OLED.

## Ejemplo de salida en pantalla

```
BIOMETRIA

HR: 78
O2: 97
```

## Código principal

```cpp
// (Aquí puedes pegar tu código final)
```

## Conclusión

Se ha conseguido implementar un sistema funcional que simula la adquisición y visualización de datos biométricos utilizando el bus I2C.

---

# 7. PARTE 2 - SERVIDOR WEB

## Objetivo

Desarrollar una página web accesible desde el navegador para visualizar los datos biométricos.

## Implementación

El ESP32 se ha configurado como servidor web mediante WiFi.

### Funcionamiento

- El ESP32 se conecta a la red WiFi
- Se inicia un servidor HTTP en el puerto 80
- Al acceder mediante navegador, se genera una página HTML dinámica

## Ejemplo de página web

```
Datos Biometricos

HR: 82
SpO2: 98
```

## Tecnologías utilizadas

- WiFi (ESP32)
- HTTP
- HTML básico

## Código principal

```cpp
// (Aquí puedes pegar el código del servidor web)
```

---

# 8. RESULTADOS

Se han conseguido los siguientes resultados:

- Comunicación I2C funcional
- Detección de dispositivos
- Control del display OLED
- Visualización dinámica de datos
- Implementación de servidor web
- Simulación de sistema biométrico

---

# 9. PROBLEMAS ENCONTRADOS Y SOLUCIONES

**Problema 1:** Pantalla con píxeles aleatorios  
**Solución:** Ajuste correcto de resolución (128x64)

**Problema 2:** Errores de compilación (duplicados)  
**Solución:** Eliminación de archivos duplicados en PlatformIO

**Problema 3:** Sensor no detectado  
**Causa:** Sensor no disponible físicamente  
**Solución:** Simulación de datos

**Problema 4:** ESP32 en modo bootloader  
**Solución:** Uso de botones BOOT y RESET

---

# 10. CONCLUSIONES

Se ha logrado comprender y aplicar el funcionamiento del bus I2C mediante la conexión de un display OLED y el desarrollo de un sistema completo de visualización de datos.

Además, se ha ampliado la funcionalidad mediante la implementación de un servidor web, permitiendo el acceso remoto a los datos.

La práctica ha permitido adquirir conocimientos en:

- Comunicación I2C
- Programación de microcontroladores
- Visualización gráfica
- Redes y servidores web embebidos

---

# 11. POSIBLES MEJORAS

- Uso de sensor real MAX30102
- Interfaz web más avanzada
- Gráficas en tiempo real
- Aplicación móvil

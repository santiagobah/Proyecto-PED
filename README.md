Sistema de Navegación Web Stella

## Este programa simula un sistema básico de navegación web con funcionalidades como apertura y cierre de pestañas, navegación entre páginas, gestión de historial, y manejo de descargas. A continuación, se explicará en detalle el propósito, estructura y funcionamiento de cada componente del programa:

### 1. Propósito del programa

### El programa ofrece una experiencia simulada de navegación web con las siguientes características:

	•	Navegación entre páginas web.
	•	Gestión de múltiples pestañas abiertas.
	•	Registro de historial de navegación.
	•	Creación, manejo y finalización de descargas.
	•	Interfaz interactiva en consola para el usuario.

### 2. Estructura del programa

### El código utiliza una combinación de clases y estructuras de datos (pilas, colas y listas) para implementar las funcionalidades principales. A continuación, se describen los principales elementos del programa:

### 2.1. Bibliotecas incluidas

	•	Pila.h, Cola.h, Lista.h: Definen las estructuras de datos utilizadas para manejar el historial, descargas y pestañas.
	•	vector: Se utiliza para almacenar y gestionar las pestañas abiertas.
	•	locale: Permite el uso de caracteres especiales como acentos.
	•	iostream: Facilita la entrada y salida de datos.

### 2.2. Estructuras de datos

	•	Pilas:
	•	Historial_de_navegacion: Registra todas las páginas visitadas en orden.
	•	Colas:
	•	Descargas: Gestiona las descargas pendientes como una lista ordenada.
	•	Listas:
	•	Pestañas_Abiertas: Maneja las pestañas abiertas y permite buscarlas, cerrarlas o modificarlas.

### 2.3. Variables importantes

	•	pestañas: Vector que contiene las URLs abiertas en las pestañas.
	•	pagina_actual: Almacena la URL activa en la pestaña actual.
	•	contador_pestañas y cant_tabs: Llevan el conteo de pestañas abiertas y totales creadas.
	•	contador_descargas: Cuenta las descargas pendientes.
	•	name_tab: Identificador único de cada pestaña.

### 2.4. Clase Pestana

### Esta clase (definida en otro archivo) maneja el historial individual de cada pestaña. Incluye métodos para agregar nuevas páginas y retroceder en la navegación.

### 3. Funcionamiento del programa

### El programa utiliza un menú interactivo en consola para que el usuario seleccione diferentes acciones. Cada opción realiza operaciones específicas y modifica las estructuras de datos internas. Aquí se explica cada opción:

### 3.1. Opciones del menú

### Opción 1: Abrir nueva página en la pestaña actual

	1.	Verifica si hay pestañas abiertas.
	2.	Solicita al usuario la URL de la página a abrir.
	3.	Actualiza el historial de la pestaña seleccionada y de navegación general.
	4.	Modifica la URL de la pestaña actual en el vector pestañas.

### Opción 2: Retroceder a página anterior

	1.	Verifica si hay pestañas abiertas.
	2.	Obtiene la página anterior desde el historial de la pestaña actual.
	3.	Actualiza la página actual y muestra un mensaje al usuario.
	4.	Si no hay más páginas en el historial, indica que la pestaña está vacía.

### Opción 3: Ver páginas anteriores de la pestaña actual

	1.	Verifica si hay pestañas abiertas.
	2.	Muestra el historial completo de la pestaña actual.

### Opción 4: Ver la pestaña actual

	1.	Verifica si hay pestañas abiertas.
	2.	Muestra la URL activa de la pestaña seleccionada.

### Opción 5: Abrir nueva pestaña

	1.	Solicita al usuario una URL para la nueva pestaña.
	2.	Genera un identificador único para la pestaña (por ejemplo, Tab1, Tab2).
	3.	Inserta la nueva pestaña en la lista de pestañas abiertas.
	4.	Actualiza el vector pestañas y los contadores relacionados.

### Opción 6: Cerrar pestaña

	1.	Solicita el número de la pestaña a cerrar.
	2.	Valida si el número corresponde a una pestaña existente.
	3.	Elimina la pestaña de la lista y del vector pestañas.
	4.	Actualiza el contador de pestañas.

### Opción 7: Ver todas las pestañas abiertas

	1.	Muestra todas las pestañas activas con su URL respectiva.

### Opción 8: Cambiar pestaña

	1.	Solicita el número de la pestaña a activar.
	2.	Cambia la pestaña activa y actualiza pagina_actual.

### Opción 9: Mostrar historial completo

	1.	Muestra el historial de navegación general, almacenado en la pila Historial_de_navegacion.

### Opción 10: Mostrar descargas pendientes

	1.	Muestra los archivos en cola de descargas pendientes.

### Opción 11: Crear nueva descarga

	1.	Solicita al usuario un nombre y un tipo de archivo (como pdf, txt, o docx).
	2.	Valida el tipo de archivo y genera un tamaño aleatorio.
	3.	Inserta la descarga en la cola Descargas.

### Opción 12: Terminar siguiente descarga pendiente

	1.	Extrae el primer archivo de la cola de descargas.
	2.	Muestra el nombre, tipo y tamaño del archivo descargado.
	3.	Actualiza el contador de descargas.

### Opción 13: Salir

	1.	Termina el programa mostrando un mensaje de despedida.

### 4. Interfaz gráfica en consola

### El programa utiliza una simulación básica de interfaz gráfica en consola:

	•	Una barra horizontal representa las pestañas abiertas, destacando la pestaña activa con ^^.
	•	Se muestra el número de descargas pendientes junto a las pestañas.

### 5. Consideraciones y manejo de errores

	•	El programa valida entradas del usuario para evitar errores como:
	•	Ingresar un número de pestaña inexistente.
	•	Seleccionar opciones inválidas en el menú.
	•	Utiliza mensajes claros para guiar al usuario en caso de errores o acciones no válidas.


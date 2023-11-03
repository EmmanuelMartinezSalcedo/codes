#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // Verificar si la clave está en el caché
        if (cacheMap.find(key) != cacheMap.end()) {
            // Mover la clave al frente de la lista (indicando que se ha utilizado recientemente)
            actualizar(key);
            return cacheMap[key];
        }
        return -1;  // Cache miss
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Si la clave ya existe en el caché, actualizar el valor y moverla al frente de la lista
            cacheMap[key] = value;
            actualizar(key);
        }
        else {
            // Si la capacidad se ha alcanzado, eliminar el elemento menos recientemente usado
            if (cacheList.size() >= capacity) {
                int keyToRemove = cacheList.back();
                cacheList.pop_back();
                cacheMap.erase(keyToRemove);
            }

            // Insertar la nueva clave y valor al frente de la lista
            cacheList.push_front(key);
            cacheMap[key] = value;
        }
    }

private:
    int capacity;
    std::list<int> cacheList;
    std::unordered_map<int, int> cacheMap;

    void actualizar(int key) {
        // Mover la clave al frente de la lista
        cacheList.remove(key);
        cacheList.push_front(key);
    }
};

int main() {
    int capacity = 2; // Capacidad de la caché
    LRUCache cache(capacity);

    // Ejemplo de uso
    cache.put(1, 1); // Agregar (1, 1) al caché
    cache.put(2, 2); // Agregar (2, 2) al caché

    std::cout << cache.get(1) << std::endl; // Devuelve 1 (hit)
    cache.put(3, 3); // Reemplaza (2, 2) por (3, 3)
    std::cout << cache.get(2) << std::endl; // Devuelve -1 (miss)
    cache.put(4, 4); // Reemplaza (1, 1) por (4, 4)
    std::cout << cache.get(1) << std::endl; // Devuelve -1 (miss)
    std::cout << cache.get(3) << std::endl; // Devuelve 3 (hit)

    return 0;
}
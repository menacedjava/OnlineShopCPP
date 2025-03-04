#include <iostream>
#include <vector>

using namespace std;

// Mahsulot klassi
class Product {
public:
    int id;
    string name;
    double price;

    Product(int id, string name, double price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    void display() {
        cout << id << ". " << name << " - $" << price << endl;
    }
};

// Do‘kon klassi
class Shop {
public:
    vector<Product> products; // Mahsulotlar ro'yxati
    vector<Product> cart; // Savatcha

    Shop() {
        // Do‘konga mahsulotlar qo‘shish
        products.push_back(Product(1, "📱 iPhone 14", 999.99));
        products.push_back(Product(2, "💻 MacBook Pro", 1999.99));
        products.push_back(Product(3, "🎧 AirPods Pro", 249.99));
        products.push_back(Product(4, "⌚ Apple Watch", 399.99));
    }

    void showProducts() {
        cout << "\n🛍️ Do‘kondagi mahsulotlar:\n";
        for (Product p : products) {
            p.display();
        }
    }

    void addToCart(int productId) {
        for (Product p : products) {
            if (p.id == productId) {
                cart.push_back(p);
                cout << "✅ " << p.name << " savatchaga qo‘shildi!\n";
                return;
            }
        }
        cout << "❌ Mahsulot topilmadi!\n";
    }

    void viewCart() {
        cout << "\n🛒 Savatchangiz:\n";
        double total = 0;
        if (cart.empty()) {
            cout << "❌ Savatcha bo‘sh!\n";
            return;
        }

        for (Product p : cart) {
            p.display();
            total += p.price;
        }
        cout << "💰 Umumiy summa: $" << total << endl;
    }

    void checkout() {
        if (cart.empty()) {
            cout << "❌ Savatcha bo‘sh! Xarid qilish uchun mahsulot qo‘shing.\n";
            return;
        }
        viewCart();
        cout << "✅ Xaridingiz muvaffaqiyatli amalga oshirildi! Rahmat!\n";
        cart.clear(); // Savatchani tozalash
    }
};

// Asosiy dastur
int main() {
    Shop shop;
    int choice;

    do {
        cout << "\n=== 🏪 ONLAYN DO'KON ===\n";
        cout << "1. Mahsulotlarni ko‘rish\n";
        cout << "2. Savatchaga qo‘shish\n";
        cout << "3. Savatchani ko‘rish\n";
        cout << "4. Xarid qilish\n";
        cout << "5. Chiqish\n";
        cout << "Tanlovingiz: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.showProducts();
                break;
            case 2:
                int productId;
                cout << "🛍️ Qaysi mahsulotni savatchaga qo‘shmoqchisiz? ID kiriting: ";
                cin >> productId;
                shop.addToCart(productId);
                break;
            case 3:
                shop.viewCart();
                break;
            case 4:
                shop.checkout();
                break;
            case 5:
                cout << "🚪 Dasturdan chiqilmoqda...\n";
                break;
            default:
                cout << "❌ Noto‘g‘ri tanlov! Qaytadan urinib ko‘ring.\n";
        }
    } while (choice != 5);

    return 0;
}

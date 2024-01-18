#include <stdio.h>
#include <string.h>

//#include "Product.h"
typedef struct Product_struct {
    char *productCode;
    double productPrice;
    int productCount;
} Product;

Product InitProduct(char *code, double price, int count); // - set the data members using the three parameters

Product SetCode(char *code, Product product); // - set the product code (i.e. SKU234) to parameter code

void GetCode(char *productCode, Product product); // - return the product code in productCode

Product SetPrice(double price, Product product); // - set the price to parameter product

double GetPrice(Product product); // - return the price

Product SetCount(int count, Product product); // - set the number of items in inventory to parameter num

int GetCount(Product product); // - return the count

Product AddInventory(int amt, Product product); // - increase inventory by parameter amt

Product SellInventory(int amt, Product product); // - decrease inventory by parameter amt

int main() {
	char code[20];
	char productCode[20];
	strcpy(code, "Apple");
	double price = 0.40;
	int num = 3;
	Product product  = InitProduct(code, price, num);

	// Test 1 - Are instance variables set/returned properly?
	GetCode(productCode, product);
	printf("Name: %s\n", productCode);
	printf("Price: %.2lf\n", GetPrice(product));
	printf("Count: %d\n\n", GetCount(product));

	// Test 2 - Are instance variables set/returned properly after adding and selling?
	num = 10;
	product = AddInventory(num, product);
	num = 5;
	product = SellInventory(num, product);
	GetCode(productCode, product);
	printf("Name: %s\n", productCode);
	printf("Price: %.2lf\n", GetPrice(product));
	printf("Count: %d\n\n", GetCount(product));

	// Test 3 - Do setters work properly?
	strcpy(code, "Golden Delicious");
	product = SetCode(code, product);
	price = 0.55;
	product = SetPrice(price, product);
	num = 4;
	product = SetCount(num, product);
	GetCode(productCode, product);
	printf("Name: %s\n", productCode);
	printf("Price: %.2lf\n", GetPrice(product));
	printf("Count: %d\n", GetCount(product));

	return 0;
}

Product InitProduct (char *code, double price, int count){
    Product newProduct;
    newProduct.productCode = code;
    newProduct.productPrice = price;
    newProduct.productCount = count;
    return newProduct;
}

Product SetCode (char *code, Product product){
    product.productCode = code;
    return product;
}

void GetCode (char *productCode, Product product){
    strcpy(productCode, product.productCode);
}

Product SetPrice(double price, Product product){
    product.productPrice = price;
    return product;
}

double GetPrice(Product product){
    return product.productPrice;
}

Product SetCount(int count, Product product){
    product.productCount = count;
    return product;
}

int GetCount(Product product){
    return product.productCount;
}

Product AddInventory(int amt, Product product){
    product.productCount += amt;
    return product;
}

Product SellInventory(int amt, Product product){
    product.productCount -= amt;
    return product;
}

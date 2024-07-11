#include <iostream>
#include <memory>
#include "Teapot.hpp"
#include "TestEvaluator.hpp"

using namespace std;

// Define a macro to use TestEvaluator for assertions
#define ASSERT(test_expr) evaluator->evaluate(#test_expr, test_expr)

int main() 
{
    // Create an instance of TestEvaluator
    auto evaluator = std::make_unique<TestEvaluator>();

    // Print the test case title
    evaluator->title("Pruebas de la Tetera");

    // Create a Teapot object with a capacity of 1000 ml
    auto tetera = std::make_unique<Teapot>(1000);

    // Perform tests
    tetera->llenar(500);
    ASSERT(tetera->obtenerCantidadActual() == 500);

    // Serve a cup of 200 ml
    ASSERT(tetera->servir(200));
    ASSERT(tetera->obtenerCantidadActual() == 300);

    // Try to serve more than the teapot contains
    ASSERT(!tetera->servir(400));
    ASSERT(tetera->obtenerCantidadActual() == 300);

    // Fill the teapot with 1500 ml (more than its capacity)
    tetera->llenar(1500);
    ASSERT(tetera->obtenerCantidadActual() == 1000);

    // Serve a cup of 100 ml
    ASSERT(tetera->servir(100));
    ASSERT(tetera->obtenerCantidadActual() == 900);

    // Print the test summary
    evaluator->summary();

    return 0;
}

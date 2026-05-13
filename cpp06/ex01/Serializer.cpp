#include "Serializer.hpp"

// --- Private constructors/destructor to prevent instantiation ---

Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }
Serializer::~Serializer() {}

// --- serialize: convert Data pointer to uintptr_t using reinterpret_cast ---

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// --- deserialize: convert uintptr_t back to Data pointer using reinterpret_cast ---

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
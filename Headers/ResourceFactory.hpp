//
// Created by Lucia on 12/15/2023.
//

#ifndef OOP_RESOURCEFACTORY_HPP
#define OOP_RESOURCEFACTORY_HPP
#include "../Headers/Resource.hpp"
#include <iostream>
#include <memory>

class ResourceFactory {
public:
    virtual std::shared_ptr<Resource> createResource() = 0;
    virtual ~ResourceFactory() = default;
};
// BookFactory
class BookFactory : public ResourceFactory {
public:
    std::shared_ptr<Resource> createResource() override;
};

// HallFactory
class HallFactory : public ResourceFactory {
public:
    std::shared_ptr<Resource> createResource() override;
};

#endif //OOP_RESOURCEFACTORY_HPP

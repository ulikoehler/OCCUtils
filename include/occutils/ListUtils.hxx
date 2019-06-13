#pragma once
#include <NCollection_List.hxx>
#include <utility> // std::pair<>
#include <vector>
#include <list>
#include <initializer_list>

namespace OCCUtils {
    namespace ListUtils {

        /**
         * Split a NCollection_List<T> into
         * a head list and a tail list.
         */
        template<typename T>
        std::pair<NCollection_List<T>, NCollection_List<T>> SplitIntoHeadAndTail(
            const NCollection_List<T>& arg,
            size_t headSize
        ) {
            auto ret = std::make_pair(NCollection_List<T>(), NCollection_List<T>());
            // Iterate arg
            for(const T& value : arg) {
                if(headSize > 0) {
                    ret.first.Append(value);
                    headSize--;
                } else {
                    ret.second.Append(value);
                }
            }
            return ret;
        }

        /**
         * Convert any STL or STL-like container of type T
         * to a NCollection_List<T>.
         */
        template<template<typename, typename> typename Container, typename T, typename Allocator>
        NCollection_List<T> ToOCCList(const Container<T, Allocator>& args) {
            NCollection_List<T> ret;
            for(const T& arg : args) {
                ret.Append(arg);
            }
            return ret;
        }

        /**
         * Convert any STL or STL-like container of type T
         * to a NCollection_List<T>.
         */
        template<typename T>
        NCollection_List<T> ToOCCList(const std::initializer_list<T>& args) {
            NCollection_List<T> ret;
            for(const T& arg : args) {
                ret.Append(arg);
            }
            return ret;
        }

        /**
         * Convert any simple-style template container to an OCC list.
         * Also: Convenience to convert an initializer list,
         * e.g. {arg1, arg2, arg3} to an OCC list
         */
        template<template<typename> typename Container, typename T>
        NCollection_List<T> ToOCCList(const Container<T>& args) {
            NCollection_List<T> ret;
            for(const T& arg : args) {
                ret.Append(arg);
            }
            return ret;
        }


        template<typename T>
        std::vector<T> ToSTLVector(const NCollection_List<T>& args) {
            std::vector<T> ret;
            ret.reserve(args.size());
            for(const T& arg : args) {
                ret.push_back(arg);
            }
            return ret;
        }

        template<typename T>
        std::list<T> ToSTLList(const NCollection_List<T>& args) {
            std::list<T> ret;
            for(const T& arg : args) {
                ret.push_back(arg);
            }
            return ret;
        }
    }
}
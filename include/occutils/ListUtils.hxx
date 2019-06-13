#pragma once
#include <NCollection_List.hxx>
#include <utility> // std::pair<>
#include <vector> // std::pair<>

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
         * Convert any STL or similar container of type T
         * to a NCollection_List<T>.
         */
        template<typename T, template<typename> typename Container>
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
    }
}
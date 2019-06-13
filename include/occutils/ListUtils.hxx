#pragma once
#include <NCollection_List.hxx>
#include <utility> // std::pair<>

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

    }
}
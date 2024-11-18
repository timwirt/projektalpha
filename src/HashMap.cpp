/**
 * @file HashMap.cpp
 * @author T. Wirtz
 * @brief Full implementation of data structure: HashMap
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <../include/Container/AbstractHashMap.hpp>
#include <functional>
#include <iostream>
#include <iterator>
#include <stdexcept>

namespace ProjektAlpha {
    using namespace std;

    class HashMapException : public runtime_error {
        public:
            explicit HashMapException(const string& message) : runtime_error(message) {}
    };

    /**
     * @brief A HashMap data structure that implements the AbstractHashMap interface
     * 
     * @tparam T The type of the elements stored in the HashMap
     */
    template <typename T>
    class HashMap : public AbstractHashMap<T> {
        
        private:
            int size;
            size_t num_buckets;

            const function<size_t(const T&)> hashfkt;
  
            list<list<T>> buckets;

        public:

            /**
             * @brief Construct a new HashMap object with default values
             * 
             */        
            HashMap (size_t num_buckets_) : hashfkt(hash<T>()), 
                                            num_buckets(num_buckets_) ,
                                            buckets(list<list<T>>(num_buckets)) {
                if (num_buckets_ <= 0) {
                    throw HashMapException("Bucket number should be >0");
                }
                size = 0;
            }

            /**
            * @brief Adds an element to the HashMap.
            *
            * @param item The element to add.
            */
            void add(T& item) override {
                size_t bucket_num = hashfkt(item) % num_buckets;

                auto bucket_it = buckets.begin();

                advance(bucket_it, bucket_num);
                list<T> bucket = *bucket_it;
                
                bucket.push_front(item);

                *bucket_it = bucket;

                size++;
            }

            /**
             * @brief Removes an element from the HashMap.
             * 
             * @param item The element to remove.
             */
            void remove(T& item) override {
                if (is_empty()) { throw HashMapException("HashMap is empty"); } 
                else if (!contains(item)) {throw HashMapException("Element is not in HashMap");}

                size_t bucket_num = hashfkt(item) % num_buckets;

                auto bucket_it = buckets.begin();
                advance(bucket_it, bucket_num);
                list<T> bucket = *bucket_it;

                auto it = std::find(bucket.begin(), bucket.end(), item);
                bucket.erase(it);

                *bucket_it = bucket;

                size--;
            }

            //  Override methods from Container

            /**
             * @brief Gets the size of the HashMap
             * 
             * @return int The size of the HashMap
             */
            int get_size() override {
                return size;
            }

            /**
             * @brief Checks whether the HashMap is empty
             * 
             * @return true if the HashMap is empty, 
             * @return false otherwise
             */
            bool is_empty() override {
                return (size == 0);
            }

            /**
             * @brief Gets the first element of the HashMap
             * 
             * @return T The first element of the HashMap
             */
            T get_first() override {
                if (is_empty()) {
                    throw HashMapException("HashMap is empty");
                } else {
                    for (list<T> bucket : buckets) {
                        if (!bucket.empty()) {
                            return *bucket.begin();
                        }
                    }
                }
                return nullptr;
            }

            /**
             * @brief Checks whether the HashMap contains the specified item
             * 
             * @param item The item to check for
             * @return true if the HashMap contains the item
             * @return false otherwise
             */
            bool contains(T& item) override {
                if (is_empty()) {
                    throw HashMapException("HashMap is empty, nothing to compare");
                }
                size_t bucket_num = hashfkt(item) % num_buckets;

                auto bucket_it = buckets.begin();
                advance(bucket_it, bucket_num);
                list<T> bucket = *bucket_it;

                for (T& content : bucket) {
                    if(content == item) {
                        return true;
                    }
                }

                return false;
            }

            /**
             * @brief Prints the contents of the HashMap to the console.
             * 
             */
            void print() override {
                size_t bucket_num = 0;

                for (list<T> bucket : buckets){
                    cout << bucket_num << ": ";
                    
                    if(bucket.empty()) {
                        cout << "NULL" << endl;;
                    } else {
                        for (T& content : bucket){
                            cout << content << "->";
                        }
                        cout << "NULL" << endl;
                    }

                    bucket_num++;
                }
            }

        /**
         * @brief This class represents an iterator for HashMap.
         * 
         * @tparam T The type of the elements stored in the HashMap.
         */
        class Iterator : public std::iterator<
                        std::forward_iterator_tag,   // iterator_category
                        T,                           // value_type
                        std::ptrdiff_t,              // difference_type
                        const T*,                    // pointer
                        T&                           // reference
                        >{
        private:
            T* data_;                                   // Pointer to the current data element
            typename list<list<T>>::iterator map_it_;   // Iterator for the current map (bucket)
            typename list<T>::iterator bucket_it_;      // Iterator for the current bucket element
            list<list<T>>& map_;                        // Reference to the list of maps (buckets)

        public:
            /**
             * @brief Construct a new Iterator object.
             * 
             * @param data A pointer to the current data element.
             * @param map A reference to the list of maps (buckets).
             */
            Iterator(T* data, list<list<T>>& map) : data_(data), map_(map) {
                // Search for first non-empty map_it_ and bucket_it_ 
                for (auto map_it = map_.begin(); map_it != map_.end(); ++map_it) {
                    if (!map_it->empty()) {
                        map_it_ = map_it;
                        bucket_it_ = map_it_->begin();
                        break;
                    }
                }
            }

            /**
             * @brief Prefix increment operator.
             * 
             * @return Iterator& A reference to the incremented iterator.
             */
            Iterator& operator++() {
                if (bucket_it_ != map_it_->end()) {
                    ++bucket_it_;
                    if (bucket_it_ == map_it_->end()) {
                        // Search for next non-empty bucket
                        ++map_it_;
                        while (map_it_ != map_.end() && map_it_->empty()) {
                            ++map_it_;
                        }
                        // If map_it_ is the end of the HashMap, it should return nullptr
                        if (map_it_ != map_.end()) {
                            bucket_it_ = map_it_->begin();
                        }
                        else {
                            data_ = nullptr;
                            return *this;
                        }
                    }
                    data_ = &(*bucket_it_);
                }
                return *this;
            }

            /**
             * @brief Postfix increment operator.
             * 
             * @return Iterator The previous state of the iterator before incrementing.
             */
            Iterator operator++(int) {Iterator temp(*this); ++(*this); return temp;}

            /**
             * @brief Equality operator.
             * 
             * @param other Another iterator to compare with.
             * @return true If the two iterators point to the same element.
             * @return false Otherwise.
             */
            bool operator==(const Iterator& other) const {return data_ == other.data_;}

            /**
             * @brief Inequality operator.
             * 
             * @param other Another iterator to compare with.
             * @return true If the two iterators point to different elements.
             * @return false Otherwise.
             */
            bool operator!=(const Iterator& other) const {return data_ != other.data_;}

            /**
             * @brief Reference operator.
             * 
             * @return T& A reference to the data element pointed by the iterator.
             */
            T& operator*() const {return *data_;}
        };


        /**
         * @brief Returns an iterator to the beginning of the HashMap
         * 
         * @return Iterator An iterator pointing to the first element in the HashMap 
         */
        Iterator begin() {
            for (auto& bucket : buckets) {
                if (!bucket.empty()) {
                    return Iterator(&bucket.front(), buckets);
                }
            }
            return Iterator(nullptr, buckets);
        }

        /**
         * @brief Returns an iterator to the end of the HashMap
         * 
         * @return Iterator An iterator pointing to the last element in the HashMap 
         */
        Iterator end() {
            return Iterator(nullptr, buckets);
        }

    };
    
}
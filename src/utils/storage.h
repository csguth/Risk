/*
 * storage.h
 *
 *  Created on: 15 de ago de 2015
 *      Author: csguth
 */

#ifndef UTILS_STORAGE_H_
#define UTILS_STORAGE_H_

#include <vector>
#include <set>

namespace risk {
namespace utils {

template<typename element_type>
class storage_t {
public:
    using id_t = std::size_t;
    using iterator = typename std::vector<element_type>::const_iterator;
    static std::size_t null_id() {
        return std::numeric_limits<id_t>::max();
    }
    virtual ~storage_t() {
    }
    virtual bool empty() const = 0;
    virtual std::size_t size() const = 0;
    virtual std::size_t max_size() const = 0;
    virtual id_t insert(const element_type element) = 0;
    virtual iterator begin() const = 0;
    virtual iterator end() const = 0;
    virtual iterator get(id_t id) const = 0;
    virtual bool remove(id_t id) = 0;
    bool full() const {
        return size() >= max_size();
    }

};

template<typename element_type>
class storage: public storage_t<element_type> {
    std::vector<element_type> m_elements;
    std::set<std::size_t> m_recycled;

    bool has(std::size_t id) const {
        return (id < m_elements.size()) && m_recycled.find(id) == m_recycled.end();
    }
public:
    using iterator = typename storage_t<element_type>::iterator;
    static const typename storage_t<element_type>::id_t null_id() {
        return std::numeric_limits<typename storage_t<element_type>::id_t>::max();
    }
    storage() {
    }
    virtual ~storage() {
    }

    virtual bool empty() const {
        return size() == 0;
    }
    virtual std::size_t size() const {
        return m_elements.size() - m_recycled.size();
    }

    virtual std::size_t max_size() const {
        return std::numeric_limits<std::size_t>::max();
    }

    virtual typename storage_t<element_type>::id_t insert(const element_type element) {
        typename storage_t<element_type>::id_t id = m_elements.size();
        if (!m_recycled.empty()) {
            id = *m_recycled.begin();
            m_recycled.erase(id);
            m_elements[id] = element;
            return id;
        }
        m_elements.push_back(element);
        return id;
    }
    virtual typename storage::iterator begin() const {
        return m_elements.cbegin();
    }
    virtual iterator end() const {
        return m_elements.cend();
    }
    virtual iterator get(typename storage_t<element_type>::id_t id) const {
        if (!has(id))
            return end();
        auto begin_it = m_elements.cbegin();
        std::advance(begin_it, id);
        return begin_it;
    }
    virtual bool remove(typename storage_t<element_type>::id_t id) {
        return has(id) && m_recycled.insert(id).second;
    }
};

template<typename element_type>
class limited_storage: public storage_t<element_type> {
    std::size_t c_max_size;
    storage<element_type> m_container;
public:
    using iterator = typename storage<element_type>::iterator;

    limited_storage(std::size_t max_size) :
        c_max_size(max_size) {
    }
    virtual ~limited_storage() {
    }
    virtual bool empty() const {
        return m_container.empty();
    }
    virtual std::size_t size() const {
        return m_container.size();
    }
    virtual std::size_t  max_size() const {
        return c_max_size;
    }
    virtual typename storage_t<element_type>::id_t insert(const element_type element) {
        if (!storage_t<element_type>::full())
            return m_container.insert(element);
        return storage_t<element_type>::null_id();
    }
    virtual iterator begin() const {
        return m_container.begin();
    }
    virtual iterator end() const {
        return m_container.end();
    }
    virtual iterator get(typename storage_t<element_type>::id_t id) const {
        return m_container.get(id);
    }
    virtual bool remove(typename storage_t<element_type>::id_t id) {
        return m_container.remove(id);
    }
};

} /* namespace utils */
} /* namespace risk */

#endif /* UTILS_STORAGE_H_ */

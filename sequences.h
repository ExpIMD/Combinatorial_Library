#ifndef __IMD_SEQUENCES_
#define __IMD_SEQUENCES_

#include <algorithm>

namespace IMD{
    const double EPSILON{1e-8};

    class arithmetic_sequence{
    private:
        long long _start;
        long long _current;
        long long _step;
        size_t _index;

    public:
        arithmetic_sequence(long long start, long long step) noexcept;

        arithmetic_sequence(const arithmetic_sequence& other) noexcept;
        arithmetic_sequence(arithmetic_sequence&& other) noexcept;

        arithmetic_sequence& operator=(const arithmetic_sequence& other) noexcept;
        arithmetic_sequence& operator=(arithmetic_sequence&&) noexcept;

        ~arithmetic_sequence() noexcept;

        long long current() const noexcept;

        void next() noexcept;
            
        void previous() noexcept;

        bool is_convergent() const noexcept;
        
        size_t index() const noexcept;

        void advance(size_t n) noexcept;
        
        void rewind(size_t n) noexcept;

        void move(size_t n) noexcept;

        void reset() noexcept;
    };

    class geometric_sequence{
    private:
        double _start;
        double _current;
        double _ratio;
        size_t _index;

    public:
        geometric_sequence(double start, double ratio) noexcept;

        geometric_sequence(const geometric_sequence& other) noexcept;
        geometric_sequence(geometric_sequence&& other) noexcept;

        geometric_sequence& operator=(const geometric_sequence& other) noexcept;
        geometric_sequence& operator=(geometric_sequence&&) noexcept;

        ~geometric_sequence() noexcept;

        double current() const noexcept;
    
        void next() noexcept;
    
        void previous() noexcept;
    
        bool is_convergent() const noexcept;

        size_t index() const noexcept;

        void advance(size_t n) noexcept;
        
        void rewind(size_t n) noexcept;

        void move(size_t n) noexcept;

        void reset() noexcept;
    };

    class Fibonacci_sequence {    
    private:
        long long _previous;
        long long _current;
        size_t _index;

    public:
        Fibonacci_sequence() noexcept;

        Fibonacci_sequence(const Fibonacci_sequence& other) noexcept;
        Fibonacci_sequence(Fibonacci_sequence&& other) noexcept;

        Fibonacci_sequence& operator=(const Fibonacci_sequence& other) noexcept;
        Fibonacci_sequence& operator=(Fibonacci_sequence&& other) noexcept;

        ~Fibonacci_sequence() noexcept;
        
        long long current() const noexcept;
        
        void next() noexcept;
        
        void previous() noexcept;
        
        bool is_convergent() const noexcept;
        
        size_t index() const noexcept;
        
        void advance(size_t n) noexcept;
        
        void rewind(size_t n) noexcept;

        void move(size_t n) noexcept;

        void reset() noexcept;
    };

    class Catalan_sequence{
    private:
        long long _current;
        size_t _index;
    
    public:
        Catalan_sequence() noexcept;

        Catalan_sequence(const Catalan_sequence& other) noexcept;
        Catalan_sequence(Catalan_sequence&& other) noexcept;

        Catalan_sequence& operator=(const Catalan_sequence& other) noexcept;
        Catalan_sequence& operator=(Catalan_sequence&& other) noexcept;

        ~Catalan_sequence() noexcept;

        long long current() const noexcept;

        void next() noexcept;

        void previous() noexcept;

        bool is_convergent() const noexcept;
        
        size_t index() const noexcept;

        void advance(size_t n) noexcept;
        
        void rewind(size_t n) noexcept;

        void move(size_t n) noexcept;

        void reset() noexcept;
    };
}

#endif
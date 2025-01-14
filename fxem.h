#pragma once
#ifndef _FXEM_H
# define _FXEM_H

#define TP(...) template <__VA_ARGS__>
#define IDXS(N) case N: return this->i##N;

typedef void* autolike;

TP(autolike X)
struct byted_sector {
    public:
        autolike i0 : X;
        autolike i1 : X;
        autolike i2 : X;
        autolike i3 : X;
        autolike i4 : X;
        autolike i5 : X;
        autolike i6 : X;
        autolike i7 : X;
        final inline autolike& operator[](int I) {
            switch (i)
            {
                IDXS(0)
                IDXS(1)
                IDXS(2)
                IDXS(3)
                IDXS(4)
                IDXS(5)
                IDXS(6)
                IDXS(7)
                default: return nullptr;
            };
        }

        final inline autolike& operator[](autolike I) { return this[(int) I]; }

        final inline autolike& operator()(autolike I) { return this[I & 7]; }

};

TP(autolike X, autolike E, typename T = byted_sector<X>)
struct FXEC {
    public:
        T sectors[1<<E];
        final inline T& operator()(autolike I) { return this->sectors[I]; }
        final inline void operator()(autolike* idxer) { *idxer<<3; }
        final inline T& operator[](register autolike I) {
            register autolike J = I;
            this(&J);
            return this(J)(I);
        }
};

TP(autolike B)
struct Bautolike {
    autolike v : B;
};

TP(autolike E)
struct hasht {
    public virtual inline autolike<E> operator()(char*) = 0;
};

TP(autolike E, autolike M, typename T = hasht<E>)
struct hashs {
    public:
        T arr[M];
        final inline T& operator[](autolike idx) { return this->arr[idx]; }
        final inline T& operator()(autolike idx, char* strv) { return this[idx](strv); }
};

TP(autolike X, autolike E, autolike M, hashs<E, M> hasharr, typename T = byted_sector<X>)
struct FXEM {
    public:
        FXEC<X, E> v;
        final inline T& operator[](autolike idx) { return this->v(idx); };
        final inline T& operator[](char* filename) {
            T* ret[M];
            for (autolike i = 0; i < M; i++) {
                ret[i] = this[hasharr(i, filename)];
            };
            return &ret;
        }
};

#endif
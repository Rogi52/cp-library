template < int input_size = 1 << 26, int output_size = 1 << 26 >
struct fast_io {
    char rdata[input_size];
    char wdata[output_size];
    char *rb;
    char *wb;
    char buf[40];
    char num[10000][4];

    fast_io() {
        std::fread(rdata, 1, input_size, stdin);
        rb = rdata;
        wb = wdata;
        for(int i = 0; i < 10000; i++) {
            int n = i;
            for(int j = 0; j < 4; j++) {
                num[i][j] = n % 10 + '0';
                n /= 10;
            }
        }
    }
    ~fast_io() {
        std::fwrite(wdata, 1, wb - wdata, stdout);
    }

    template < typename Int > inline void in(Int& x) {
        while(*rb != '-' and !('0' <= *rb and *rb <= '9')) ++rb;
        x = 0;
        if(*rb != '-') {
            while('0' <= *rb and *rb <= '9') {
                x = 10 * x + (*rb - '0');
                ++rb;
            }
        } else {
            ++rb;
            while('0' <= *rb and *rb <= '9') {
                x = 10 * x - (*rb - '0');
                ++rb;
            }
        }
    }

    template < typename Int > inline void out(Int x) {
        if(x == 0) { *(wb++) = '0'; return; }
        char *b = buf;

        if(x > 0) {
            while(x >= 10000) {
                Int q = x / 10000;
                std::memcpy(b, num[x - 10000 * q], 4);
                b += 4;
                x = q;
            }
            while(x) {
                Int q = x / 10;
                *(b++) = x - 10 * q + '0';
                x = q;
            }
        } else {
            while(x <= -10000) {
                Int q = x / 10000;
                std::memcpy(b, num[10000 * q - x], 4);
                b += 4;
                x = q;
            }
            while(x) {
                Int q = x / 10;
                *(b++) = 10 * q - x + '0';
                x = q;
            }
            *(b++) = '-';
        }
        while(b != buf) *(wb++) = *(--b);
    }

    inline void out(char c) {
        *(wb++) = c;
    }
};
fast_io io;

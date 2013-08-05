
#ifndef _AIR_MODES_PREAMBLE_IMPL_H_
#define _AIR_MODES_PREAMBLE_IMPL_H_

#include <gnuradio/block.h>
#include <gr_air_modes/api.h>
#include <gr_air_modes/preamble.h>

namespace gr {
namespace air_modes {

class AIR_MODES_API preamble_impl : public preamble
{
private:
    int d_check_width;
    int d_chip_rate;
    float d_preamble_length_us;
    int d_samples_per_chip;
    int d_samples_per_symbol;
    float d_threshold_db;
    float d_threshold;
    pmt::pmt_t d_me, d_key;
    gr::tag_t d_timestamp;
    double d_secs_per_sample;

public:
    preamble_impl(int channel_rate, float threshold_db);

    int general_work (int noutput_items,
              gr_vector_int &ninput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items);

    void set_rate(int channel_rate);
    void set_threshold(float threshold_db);
    float get_threshold(void);
    int get_rate(void);
};

} //namespace air_modes
} //namespace gr

#endif //_AIR_MODES_PREAMBLE_IMPL_H_

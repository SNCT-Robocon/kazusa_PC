#ifndef PID_CONTROL_HPP_
#define PID_CONTROL_HPP_

#include <algorithm>
#include <cmath>


class pid_control{

private:
    float loop_hz;
    float gain_p, gain_i, gain_d;
    float lim_abs;
    float old_diff;
    float diff_integ;

    float integ_lim_abs;
    float half_inv_loop_hz;

public:

    pid_control(
        float _loop_hz,
        float _gain_p,
        float _gain_i,
        float _gain_d,
        float _lim_abs
    ) : loop_hz(_loop_hz),
        gain_p(_gain_p),
        gain_i(_gain_i),
        gain_d(_gain_d),
        lim_abs(_lim_abs),
        old_diff(0.0f),
        diff_integ(0.0f)
    {
        integ_lim_abs = lim_abs / gain_i;
        half_inv_loop_hz = 0.5f / loop_hz;
    }

    float calculate_output(float diff){
        float output = 0.0f;

        diff_integ += (diff + old_diff) * half_inv_loop_hz;
        diff_integ = std::clamp(diff_integ, - integ_lim_abs, integ_lim_abs);

        output += diff * gain_p;
        output += (diff - old_diff) * this -> loop_hz * gain_d;
        output += diff_integ * gain_i;

        old_diff = diff;

        output = std::clamp(output, - lim_abs, lim_abs);

        return output;
    }

    void set_gain(float _gain_p, float _gain_i, float _gain_d){
        gain_p = _gain_p;
        gain_i = _gain_i;
        gain_d = _gain_d;
        integ_lim_abs = lim_abs / gain_i;
    }

    void set_lim(float _lim_abs){
        lim_abs = _lim_abs;
        integ_lim_abs = lim_abs / gain_i;
    }

    void reset(void){
        old_diff = 0.0f;
        diff_integ = 0.0f;
    }

};


#endif /* PID_CONTROL_HPP_ */
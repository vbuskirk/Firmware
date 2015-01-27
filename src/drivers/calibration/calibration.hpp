#pragma once

#include <mathlib/mathlib.h>

/*
 * common sensor scaling factors; Vout = Vscale * (Vin + Voffset)
 */

struct __EXPORT calibration_values_s {
	math::Vector<3> offsets;
	math::Vector<3> scales;
	inline calibration_values_s() {
		scales.set(1.0f);
	}
};

/**
 * Inheritance enables overloading for parameter saving
 */
struct __EXPORT accel_calibration_s : calibration_values_s {};
struct __EXPORT gyro_calibration_s : calibration_values_s {};

__EXPORT bool set_calibration_parameters (const char* const offset_params[3], const char* const scale_params[3],
		const calibration_values_s &calibration);
__EXPORT bool set_calibration_parameters (const accel_calibration_s &accel_calibration);
__EXPORT bool set_calibration_parameters (const gyro_calibration_s &gyro_calibration);

__EXPORT bool get_calibration_parameters (const char* const offset_params[3], const char* const scale_params[3],
		calibration_values_s *calibration);
__EXPORT bool get_calibration_parameters (accel_calibration_s *accel_calibration);
__EXPORT bool get_calibration_parameters (gyro_calibration_s *gyro_calibration);

__EXPORT void print_calibration(calibration_values_s calibration, int mavlink_fd);

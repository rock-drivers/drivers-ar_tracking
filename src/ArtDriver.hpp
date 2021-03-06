#ifndef __ART_DRIVER_HPP__
#define __ART_DRIVER_HPP__

#include <base/Time.hpp>
#include <base/Eigen.hpp>
#include <boost/shared_ptr.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <vector>

namespace artracking
{

	class ARTDriver
	{
	public:
		ARTDriver();

		bool connect (const std::string& server_host, unsigned short server_port, unsigned short data_port);
		bool isConnected();
		void disconnect();
		bool getFrame( const base::Time& timeout = base::Time::fromSeconds(1.0) );
		base::Time getTimestamp();
		Eigen::Affine3d getSegmentTransform(int numBody);
		Eigen::Quaterniond r_to_q( double r[]);
		bool error_to_console();
		void output_to_console();
	};

}
#endif

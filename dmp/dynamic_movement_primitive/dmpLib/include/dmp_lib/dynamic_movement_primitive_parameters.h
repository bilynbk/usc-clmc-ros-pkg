/*********************************************************************
 Computational Learning and Motor Control Lab
 University of Southern California
 Prof. Stefan Schaal
 *********************************************************************
 \remarks		...
 
 \file		parameters.h

 \author	Peter Pastor, Mrinal Kalakrishnan
 \date		Nov 4, 2010

 *********************************************************************/

#ifndef DYNAMIC_MOVEMENT_PRIMITIVE_PARAMETERS_BASE_H_
#define DYNAMIC_MOVEMENT_PRIMITIVE_PARAMETERS_BASE_H_

// system include
#include <string>
#include <boost/shared_ptr.hpp>

// local include
#include <dmp_lib/time.h>

namespace dmp_lib
{

/*! Parameters of a DMP that need to be save to file
 */
class DynamicMovementPrimitiveParameters
{

  /*! Allow the DynamicMovementPrimitive class to access private member variables directly
   */
  friend class DynamicMovementPrimitive;

public:

  /*! Constructor
   */
  DynamicMovementPrimitiveParameters() :
    teaching_duration_(0), execution_duration_(0), cutoff_(0), type_(-1) {};

  /*! Destructor
   */
  virtual ~DynamicMovementPrimitiveParameters() {};

  /*!
   * @param initial_time
   * @param teaching_duration
   * @param execution_duration
   * @param cutoff
   * @param type
   * @return True on success, otherwise False
   */
  bool initialize(const Time& initial_time,
                  const double teaching_duration,
                  const double execution_duration,
                  const double cutoff,
                  const int type);

  /*!
   * @param cutoff
   */
  bool setCutoff(const double cutoff);

  /*!
   * @param parameters
   * @return
   */
  bool isCompatible(const DynamicMovementPrimitiveParameters& other_parameters) const;

  /*!
   * @param other_parameters
   * @return
   */
  bool changeType(const DynamicMovementPrimitiveParameters& other_parameters);

  /*!
   * @param initial_time
   * @param teaching_duration
   * @param execution_duration
   * @param cutoff
   * @param type
   * @return True on success, otherwise False
   */
  bool get(Time& initial_time,
           double& teaching_duration,
           double& execution_duration,
           double& cutoff,
           int& type) const;

private:

  /*! Time parameters which have been used during learning
   */
  Time initial_time_;

  /*! Default durations are important to find values for alpha_z to
   *  obtain desired behavior
   */
  double teaching_duration_;
  double execution_duration_;

  /*! Defines when a particular movement has finished.
   */
  double cutoff_;

  /*! Type of the DMP
   */
  int type_;

};

/*! Abbreviation for convinience
 */
typedef DynamicMovementPrimitiveParameters DMPParam;
typedef boost::shared_ptr<DMPParam> DMPParamPtr;
typedef boost::shared_ptr<DMPParam const> DMPParamConstPtr;

}

#endif /* DYNAMIC_MOVEMENT_PRIMITIVE_PARAMETERS_BASE_H_ */

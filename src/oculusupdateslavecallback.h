/*
 * oculusupdateslavecallback.h
 *
 *  Created on: Jul 07, 2015
 *      Author: Björn Blissing
 */
#include <osgViewer/View>
#include "oculusdevice.h"

struct OculusUpdateSlaveCallback : public osg::View::Slave::UpdateSlaveCallback
{
	enum CameraType
	{
		LEFT_CAMERA,
		RIGHT_CAMERA
	};

	OculusUpdateSlaveCallback(CameraType cameraType, OculusDevice* device, OculusSwapCallback* swapCallback) :
		m_cameraType(cameraType),
		m_device(device),
		m_swapCallback(swapCallback) {}

	virtual void updateSlave(osg::View& view, osg::View::Slave& slave);

	CameraType m_cameraType;
	osg::ref_ptr<OculusDevice> m_device;
	osg::ref_ptr<OculusSwapCallback> m_swapCallback;
};
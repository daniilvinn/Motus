#include <motus_pch.h>
#include "OrthoCamera.h"

namespace Motus {

	OrthographicCamera::OrthographicCamera()
	{
		m_ViewMatrix = glm::mat4(1.0f);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		m_CameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
		m_Rotation = 0.0f;
	}

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
	{
		m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		m_ViewMatrix = glm::mat4(1.0f);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		m_CameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
		m_Rotation = 0.0f;
	}
	

	OrthographicCamera::~OrthographicCamera()
	{
		
	}
	
	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
	{
		m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		CalculateMatrix();
	}

	void OrthographicCamera::CalculateMatrix()
	{
		glm::mat4 transform =
			glm::translate(glm::mat4(1.0f), m_CameraPosition) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

		m_ViewMatrix = glm::inverse(transform);
		MT_CORE_ASSERT(m_ProjectionMatrix != glm::mat4(1.0f), "Projection matrix is not specified!");
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

}
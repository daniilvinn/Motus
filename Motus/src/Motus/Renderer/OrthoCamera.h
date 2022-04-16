#pragma once

#include <Motus/Core/Base.h>

#include <glm/gtc/matrix_transform.hpp>

namespace Motus {

	class MOTUS_API OrthographicCamera {
	public:
		OrthographicCamera();
		OrthographicCamera(float left, float right, float bottom, float top);
		~OrthographicCamera();

		const glm::mat4& GetVPMatrix() const { return m_ViewProjectionMatrix; };
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; };
		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; };

		void SetPosition(glm::vec3 pos) { m_CameraPosition = pos; CalculateMatrix(); };
		void SetRotation(float rotation) { m_Rotation = rotation; CalculateMatrix(); };
		void SetProjection(float left, float right, float bottom, float top);

	private:
		void CalculateMatrix();
	private:
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_CameraPosition;
		float m_Rotation;
	};

}
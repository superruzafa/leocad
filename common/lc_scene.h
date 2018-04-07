#pragma once

#include "lc_mesh.h"
#include "lc_array.h"

class lcScene
{
public:
	lcScene();

	void SetActiveSubmodelInstance(lcPiece* ActiveSubmodelInstance)
	{
		mActiveSubmodelInstance = ActiveSubmodelInstance;
	}

	lcPiece* GetActiveSubmodelInstance() const
	{
		return mActiveSubmodelInstance;
	}

	void SetDrawInterface(bool DrawInterface)
	{
		mDrawInterface = DrawInterface;
	}

	bool GetDrawInterface() const
	{
		return mDrawInterface;
	}

	void SetAllowWireframe(bool AllowWireframe)
	{
		mAllowWireframe = AllowWireframe;
	}

	void Begin(const lcMatrix44& ViewMatrix);
	void End();
	void AddMesh(lcMesh* Mesh, const lcMatrix44& WorldMatrix, int ColorIndex, lcRenderMeshState State, int Flags);

	void AddInterfaceObject(const lcObject* Object)
	{
		mInterfaceObjects.Add(Object);
	}

	void Draw(lcContext* Context) const;
	void DrawInterfaceObjects(lcContext* Context) const;

protected:
	void DrawRenderMeshes(lcContext* Context, int PrimitiveTypes, bool EnableNormals, bool DrawTranslucent, bool DrawTextured) const;

	lcMatrix44 mViewMatrix;
	lcPiece* mActiveSubmodelInstance;
	bool mDrawInterface;
	bool mAllowWireframe;

	lcArray<lcRenderMesh> mRenderMeshes;
	lcArray<int> mOpaqueMeshes;
	lcArray<int> mTranslucentMeshes;
	lcArray<const lcObject*> mInterfaceObjects;
	bool mHasTexture;
};

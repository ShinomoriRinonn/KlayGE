// SceneObjectHelper.cpp
// KlayGE 一些常用的可渲染对象 实现文件
// Ver 2.7.1
// 版权所有(C) 龚敏敏, 2005
// Homepage: http://klayge.sourceforge.net
//
// 2.7.1
// 增加了RenderableHelper基类 (2005.7.10)
//
// 2.6.0
// 增加了RenderableSkyBox (2005.5.26)
//
// 2.5.0
// 增加了RenderablePoint，RenderableLine和RenderableTriangle (2005.4.13)
//
// 2.4.0
// 初次建立 (2005.3.22)
//
// 修改记录
//////////////////////////////////////////////////////////////////////////////////

#include <KlayGE/KlayGE.hpp>
#include <KlayGE/Util.hpp>
#include <KlayGE/RenderableHelper.hpp>

#include <boost/tuple/tuple.hpp>

#include <KlayGE/SceneObjectHelper.hpp>

namespace KlayGE
{
	SceneObjectHelper::SceneObjectHelper(bool can_be_culled, bool short_age)
		: can_be_culled_(can_be_culled), short_age_(short_age)
	{
	}

	SceneObjectHelper::SceneObjectHelper(RenderablePtr renderable,
			bool can_be_culled, bool short_age)
		: can_be_culled_(can_be_culled), short_age_(short_age)
	{
		renderable_ = renderable;
	}

	bool SceneObjectHelper::CanBeCulled() const
	{
		return can_be_culled_;
	}
	
	bool SceneObjectHelper::ShortAge() const
	{
		return short_age_;
	}

	SceneObjectSkyBox::SceneObjectSkyBox()
		: SceneObjectHelper(RenderablePtr(new RenderableSkyBox), false, false)
	{
	}

	void SceneObjectSkyBox::CubeMap(TexturePtr const & cube)
	{
		checked_cast<RenderableSkyBox*>(renderable_.get())->CubeMap(cube);
	}
}

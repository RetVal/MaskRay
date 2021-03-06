/*
 * $File: renderable.cc
 * $Date: Mon Jun 24 03:41:45 2013 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include "renderable.hh"

#include "material.hh"
#include "texture_mapper.hh"

Renderable::Renderable(std::string name,
		Geometry * geometry,
		SurfaceProperty * surface_property,
		TextureMapper * texture_mapper,
		Material * material):
	name(name),
	geometry(geometry),
	surface_property(surface_property),
	texture_mapper(texture_mapper),
	material(material)
{
	if (material == nullptr)
		material = new VacuumMaterial();
}

Renderable::~Renderable(
		)
{
		delete geometry;
		delete surface_property;
		delete texture_mapper;
		delete material;
}

IntersectInfo * Renderable::intersect(const Ray &ray)
{
	// TODO: Bounding Box

	auto geoii = geometry->intersect(ray);
	if (!geoii)
		return nullptr;
	IntersectInfo * ret;
	ret = new IntersectInfo();
	ret->intersect_info = geoii;
	ret->renderable = this;

	return ret;
}

/**
 * vim: syntax=cpp11 foldmethod=marker
 */


#pragma once

#include "../settings.h"
#include "../helpers/math.h"
#include "../valve_sdk/csgostructs.hpp"
#include <vector>

namespace features
{
	void bhop(CUserCmd* cmd);
	void moon_walk(CUserCmd* cmd);
	void auto_strafe(CUserCmd* cmd);
	void thirdperson();
	void human_bhop(CUserCmd* cmd);
	void SelfNade(CUserCmd* cmd);
	void fastStop(CUserCmd* cmd);
	void edgeJumpPre(CUserCmd* cmd) noexcept;
	void edgeJumpPost(CUserCmd* cmd) noexcept;
	void blockBot(CUserCmd* cmd);
}

namespace color_modulation
{
	void event();
	void handle();
	void SkyChanger();
	void SetMatForce();
}

namespace fake_lags
{
	void handle(CUserCmd* cmd, bool& send_packet);
}

namespace visuals
{
	void fetch_entities();
	void render(ImDrawList* draw_list);
	void more_chams() noexcept;
	void glow() noexcept;
	void glow_override() noexcept;
	void RenderPunchCross();
	void RenderHitmarker();
	void RenderNoScopeOverlay();
	void SpreadCircle();
	void bomb_esp(c_planted_c4* entity) noexcept;
	void DrawFov(); //todo
	void Choke();
	void DesyncChams();
	void AAIndicator();
	void KnifeLeft();
	void DrawRing3D();
	void DrawDamageIndicator();
	void runCM(CUserCmd* cmd);
	void RenderInfo(ImDrawList* draw_list);
	void RenderCircle(ImDrawList* draw_list);
	void remove_3dsky();
	void remove_shadows();
}

namespace esp
{
	void render(ImDrawList* draw_list);
}

namespace aimbot
{
	void handle(CUserCmd* pCmd);
	void OnMove(CUserCmd* pCmd);
	float get_fov();
	float GetFov();
}

namespace glows
{
	void handle();
	void shutdown();
}

namespace skins
{
	extern std::map<int, item_setting> m_items;
	extern std::map<int, statrack_setting> statrack_items;
	extern std::unordered_map<std::string, std::string> m_icon_overrides;

	extern std::vector<paint_kit_t> skin_kits;

	extern std::vector<weapon_name_t> knife_names;
	extern std::vector<weapon_name_t> glove_names;

	void save();
	void LoadStatrack();
	void SaveStatrack();
	void load();
	void initialize_kits();

	void handle();

	const weapon_info_t* get_weapon_info(const int& defindex);
	const char* get_icon_override(const std::string& original);
}

namespace zeusbot
{
	void handle(CUserCmd* cmd);
}

namespace grenade_prediction
{
	void fetch_points(CUserCmd* cmd);
	void render(ImDrawList* draw_list);

	int PhysicsClipVelocity(const Vector& in, const Vector& normal, Vector& out, float overbounce);
	void PushEntity(Vector& src, const Vector& move, trace_t& tr);
	void TraceHull(Vector& src, Vector& end, trace_t& tr);
	void AddGravityMove(Vector& move, Vector& vel, float frametime, bool onground);
	void ResolveFlyCollisionCustom(trace_t& tr, Vector& vecVelocity, float interval);
	void Setup(Vector& vecSrc, Vector& vecThrow, QAngle viewangles);
}

namespace offscreen_entities
{
	extern ImU32 sound_color;
	extern ImU32 origin_color;

	void dot(const Vector& origin, const Vector& pos, const ImU32& color);
	void render(ImDrawList* draw_list);
}

namespace engine_prediction
{
	void start(CUserCmd* cmd);
	void finish(CUserCmd* cmd);
}

namespace clantag
{
	void set(const char* tag);
	void set(const char* tag, const char* label);

	void restore();
	void animate();
}

namespace desync
{
	extern bool flip_yaw;
}

namespace slow_walk
{
	void handle(CUserCmd* cmd);
}

namespace knife_bot
{
	void handle(CUserCmd* cmd, bool& send_packet);
}

namespace resolver
{
	void handle();
}

namespace no_flash
{
	void handle();
}

namespace no_smoke
{
	void event();
	void handle();
}
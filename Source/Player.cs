using System;

namespace Harley
{
	public class Player{
		private int hp;
		private int stamina;
		private int attack_strength;
		private int defence;
		private int weight;
		private int max_weight_load;

		private int tile_x;
		private int tile_y;
		private int battle_x;
		private int battle_y;

		private Ability ability;
		private SpecialAttack special_attack;


		public Player()
		{
			hp = 100;
			stamina = 100;
			attack_strength = 12;
			defence = 5;
			weight = 9;
			max_weight_load = 0;
			tile_x = 4;
			tile_y = 4;
			battle_x = 4;
			battle_y = 4;
			ability = new HealthRegenAbility ();
			special_attack = new SpecialAttack ();
		}


		public void attack()
		{
			/* To be implemented. */
		}

		public void strike()
		{
			/* To be implemented. */
		}

		public void special()
		{
			/* To be implemented. */
		}

		public void block()
		{
			/* To be implemented. */
		}

		public void dealdamage(int damage)
		{
			/* To be implemented. */
		}

		public int Health
		{
			get { return hp; }
		}

		public int Stamina
		{
			get { return stamina; }
		}

		public int BattleX
		{
			get { return battle_x; }
		}

		public int BattleY {
			get { return battle_y; }
		}

		public void startBattle()
		{
			/* To be implemented. */
		}
	}
}
#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "rope.h"
#include "spring.h"

namespace CGL {

Rope::Rope(Vector2D start, Vector2D end, int num_nodes, float node_mass,
           float k, vector<int> pinned_nodes) {
    // TODO (Part 1): Create a rope starting at `start`, ending at `end`, and
    // containing `num_nodes` nodes.

    for (int i = 0; i < num_nodes; i++) {
        auto m = new Mass(start + (float(i) / num_nodes) * (end - start),
                          node_mass, false);
        m->start_position = m->position;
        m->last_position = m->position;
        masses.push_back(m);
        if (i != 0) {
            auto s = new Spring(masses[i - 1], masses[i], k);
            s->rest_length = (s->m2->position - s->m1->position).norm();
            springs.push_back(s);
        }
    }

    //        Comment-in this part when you implement the constructor
    for (auto &i : pinned_nodes) {
        masses[i]->pinned = true;
    }
}

void Rope::simulateEuler(float delta_t, Vector2D gravity) {
    for (auto &s : springs) {
        // TODO (Part 2): Use Hooke's law to calculate the force on a node
        auto dx = (s->m2->position - s->m1->position);
        auto f = s->k * (dx.norm() - s->rest_length) * (dx / dx.norm());
        s->m1->forces += f;
        s->m2->forces -= f;
    }

    for (auto &m : masses) {
        if (!m->pinned) {
            // TODO (Part 2): Add the force due to gravity, then compute the new
            // velocity and position
            m->forces += gravity * m->mass;
            // explicit Euler
            // m->position = m->position + delta_t * m->velocity;
            m->velocity = m->velocity + delta_t * m->forces / m->mass;
            // semi-implicit Euler
            m->position = m->position + delta_t * m->velocity;
            // TODO (Part 2): Add global damping
        }

        // Reset all forces on each mass
        m->forces = Vector2D(0, 0);
    }
}

void Rope::simulateVerlet(float delta_t, Vector2D gravity) {
    for (auto &s : springs) {
        // TODO (Part 3): Simulate one timestep of the rope using explicit
        // Verlet （solving constraints)
        auto dx = (s->m2->position - s->m1->position);
        auto f = s->k * (dx.norm() - s->rest_length) * (dx / dx.norm());
        s->m1->forces += f;
        s->m2->forces -= f;
    }

    for (auto &m : masses) {
        if (!m->pinned) {
            Vector2D temp_position = m->position;
            // TODO (Part 3.1): Set the new position of the rope mass
            m->forces += gravity * m->mass;
            auto a = m->forces / m->mass;
            float damping = 0.00005;
            m->position = temp_position +
                          (1 - damping) * (temp_position - m->last_position) +
                          a * delta_t * delta_t;
            // m->position = temp_position + (temp_position - m->last_position)
            // +
            //               a * delta_t * delta_t;
            m->last_position = temp_position;
            // TODO (Part 4): Add global Verlet damping
            m->forces = Vector2D(0, 0);
        }
    }
}
} // namespace CGL
